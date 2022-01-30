// Fill out your copyright notice in the Description page of Project Settings.


#include "XPlayerCharacter.h"
#include "XPlayerController.h"
#include "GameFramework/PawnMovementComponent.h"

AXPlayerCharacter::AXPlayerCharacter()
{
	MyAbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	MyAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UBaseAttributes::GetBodyAttribute()).AddUObject(this, &AXPlayerCharacter::OnAttrUpdated);
	MyAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UBaseAttributes::GetReikiAttribute()).AddUObject(this, &AXPlayerCharacter::OnAttrUpdated);
	MyAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UBaseAttributes::GetMentalityAttribute()).AddUObject(this, &AXPlayerCharacter::OnAttrUpdated);
}

void AXPlayerCharacter::OnAttrUpdated(const FOnAttributeChangeData& Data) const
{
	if(Data.Attribute==UBaseAttributes::GetBodyAttribute())
	{
		OnAttributeChange.Broadcast(Data.NewValue,"Body");
	}
	if(Data.Attribute==UBaseAttributes::GetReikiAttribute())
	{
		OnAttributeChange.Broadcast(Data.NewValue,"Reiki");
	}
	if(Data.Attribute==UBaseAttributes::GetMentalityAttribute())
	{
		OnAttributeChange.Broadcast(Data.NewValue,"Mentality");
	}
}

void AXPlayerCharacter::SetupPlayerInputComponent(class UInputComponent * PlayerInputComponent)
{
	if (MyAbilitySystemComponent)
	{
		MyAbilitySystemComponent->BindAbilityActivationToInputComponent(PlayerInputComponent, FGameplayAbilityInputBinds(TEXT("CONFIRM"), TEXT("CANCEL"),
			TEXT("EXZAbilityInputID"), static_cast<int32>(EXZAbilityInputID::CONFIRM), static_cast<int32>(EXZAbilityInputID::CANCEL)));
	}
}

void AXPlayerCharacter::UpdateAbilityFactor() 
{
	InitAbilityFactor();
	FHitResult HitResult;
	Cast<AXPlayerController>(GetController())->GetHitResultUnderCursorByChannel(TraceTypeQuery2, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		if (HitResult.GetActor()->Tags.Contains("Monster")) {
			ReleaseTarget.TargetActor = HitResult.GetActor();
		}
		ReleaseTarget.TargetLocation = HitResult.Location;
	}
}

void AXPlayerCharacter::InitAbilityFactor()
{
	ReleaseTarget.TargetActor = nullptr;
	ReleaseTarget.TargetLocation = FVector(NAN);
	ReleaseTarget.FireAbility = nullptr;
}

void AXPlayerCharacter::StartFireAbility()
{
	GetMovementComponent()->StopActiveMovement();
	if (ReleaseTarget.FireAbility) {
		MyAbilitySystemComponent->TryActivateAbilityByClass(ReleaseTarget.FireAbility);
	}
}
