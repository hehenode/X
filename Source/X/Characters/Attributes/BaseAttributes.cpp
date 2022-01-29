// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAttributes.h"
#include "Net/UnrealNetwork.h"

void UBaseAttributes::OnRep_Body(const FGameplayAttributeData& OldBody)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, Body, OldBody);
}

void UBaseAttributes::OnRep_MaxBody(const FGameplayAttributeData& OldMaxBody)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, MaxBody, OldMaxBody);
}

void UBaseAttributes::OnRep_Reiki(const FGameplayAttributeData& OldReiki)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, Reiki, OldReiki);
}

void UBaseAttributes::OnRep_MaxReiki(const FGameplayAttributeData& OldMaxReiki)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, MaxReiki, OldMaxReiki);
}

void UBaseAttributes::OnRep_Mentality(const FGameplayAttributeData& OldMentality)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, Mentality, OldMentality);
}

void UBaseAttributes::OnRep_MaxMentality(const FGameplayAttributeData& OldMaxMentality)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, MaxMentality, OldMaxMentality);
}

void UBaseAttributes::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, Body, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, MaxBody, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, Reiki, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, MaxReiki, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, Mentality, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, MaxMentality, COND_None, REPNOTIFY_Always);
}

void UBaseAttributes::PostAttributeChange(const FGameplayAttribute & Attribute,float OldValue,float NewValue)
{
	if(Attribute==GetBodyAttribute())
	{
		OnAttributeChange.Broadcast(NewValue,"Body");
	}
	if(Attribute==GetReikiAttribute())
	{
		OnAttributeChange.Broadcast(NewValue,"Reiki");
	}
	if(Attribute==GetMentalityAttribute())
	{
		OnAttributeChange.Broadcast(NewValue,"Mentality");
	}
}

void UBaseAttributes::PostAttributeBaseChange(const FGameplayAttribute & Attribute,float OldValue,float NewValue)const
{
	if(Attribute==GetBodyAttribute())
	{
		OnAttributeChange.Broadcast(NewValue,"Body");
	}
	if(Attribute==GetReikiAttribute())
	{
		OnAttributeChange.Broadcast(NewValue,"Reiki");
	}
	if(Attribute==GetMentalityAttribute())
	{
		OnAttributeChange.Broadcast(NewValue,"Mentality");
	}
}
