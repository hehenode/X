// Fill out your copyright notice in the Description page of Project Settings.


#include "XPlayerCharacter.h"

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

