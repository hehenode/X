// Copyright Epic Games, Inc. All Rights Reserved.

#include "XCharacter.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AXCharacter::AXCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;

	MyAbilitySystemComponent = CreateDefaultSubobject<UXAbilitySystemComponent>(TEXT("MyAbilitySystem"));
	MyAbilitySystemComponent->SetIsReplicated(true);
}

UXAbilitySystemComponent* AXCharacter::GetAbilitySystemComponent() const
{
	return MyAbilitySystemComponent;
}

void AXCharacter::PossessedBy(AController * NewController)
{
	Super::PossessedBy(NewController);
	if (MyAbilitySystemComponent)
	{
		MyAbilitySystemComponent -> InitAbilityActorInfo(this, this);
	}
	SetOwner(NewController);
	InitAttributes();
	AddStartUpEffects();
	AddCharacterStartupAbilities();
}

void AXCharacter::InitAttributes()
{
	if (!MyAbilitySystemComponent)
	{
		return;
	}
	if (!DefaultAttributes)
	{
		return;
	}
	FGameplayEffectContextHandle EffectContextHandle = MyAbilitySystemComponent->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	
	const FGameplayEffectSpecHandle SpecHandle = MyAbilitySystemComponent->MakeOutgoingSpec(DefaultAttributes, CharacterLevel, EffectContextHandle);
	if (SpecHandle.IsValid())
	{
		MyAbilitySystemComponent->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), MyAbilitySystemComponent);
	}
}

void AXCharacter::AddCharacterStartupAbilities()
{
	if (GetLocalRole() != ROLE_Authority || !MyAbilitySystemComponent || MyAbilitySystemComponent->bHasGiveCharacterAbilities)
	{
		return;
	}
	for (auto ga : CharacterAbilities)
	{
		FGameplayAbilitySpec spec = FGameplayAbilitySpec(ga,ga.GetDefaultObject()->GetAbilityLevel(), static_cast<int32>(ga.GetDefaultObject()->InputID), this);
		MyAbilitySystemComponent->GiveAbility(spec);

	}
	MyAbilitySystemComponent->bHasGiveCharacterAbilities = true;
}

void AXCharacter::AddStartUpEffects()
{
	if (GetLocalRole() != ROLE_Authority || !MyAbilitySystemComponent || MyAbilitySystemComponent->bHasApplyStartupEffects)
	{
		return;
	}

	FGameplayEffectContextHandle EffectContextHandle = MyAbilitySystemComponent->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	for (auto ge : StartupEffects)
	{
		FGameplayEffectSpecHandle SpecHandle = MyAbilitySystemComponent->MakeOutgoingSpec(ge, CharacterLevel, EffectContextHandle);
		if (SpecHandle.IsValid())
		{
			MyAbilitySystemComponent->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), MyAbilitySystemComponent);
		}
	}
	MyAbilitySystemComponent->bHasApplyStartupEffects = true;
}

bool AXCharacter::ReachReleaseDistance(const FVector TargetLocation, const float Distance)
{
	return FVector::Dist(GetActorLocation(), TargetLocation) < Distance;
}
