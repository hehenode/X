// Fill out your copyright notice in the Description page of Project Settings.


#include "FatherGameplayAbility.h"
#include "AbilitySystemComponent.h"

UFatherGameplayAbility::UFatherGameplayAbility()
{
	InstancingPolicy=EGameplayAbilityInstancingPolicy::InstancedPerActor;
	bServerRespectsRemoteAbilityCancellation=false;
}

void UFatherGameplayAbility::OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnAvatarSet(ActorInfo, Spec);
	if (bAutoActivate)
	{
		ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle, false);
	}
}

void UFatherGameplayAbility::SetAbilityLevel(int32 Level) const
{
	GetCurrentAbilitySpec()->Level = Level;
}