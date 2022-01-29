// Fill out your copyright notice in the Description page of Project Settings.


#include "RarityComponent.h"

// Sets default values for this component's properties
URarityComponent::URarityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	Rarity = FGameplayTag::RequestGameplayTag(FName("Rarity.One"));
	RarityMap={
		{FGameplayTag::RequestGameplayTag(FName("Rarity.One")),{UTF8_TO_TCHAR("下品"),UTF8_TO_TCHAR("生灵"),1}},
		{FGameplayTag::RequestGameplayTag(FName("Rarity.Two")),{UTF8_TO_TCHAR("中品"),UTF8_TO_TCHAR("人杰"),2}},
		{FGameplayTag::RequestGameplayTag(FName("Rarity.Three")),{UTF8_TO_TCHAR("上品"),UTF8_TO_TCHAR("天骄"),3}},
		{FGameplayTag::RequestGameplayTag(FName("Rarity.Four")),{UTF8_TO_TCHAR("极品"),UTF8_TO_TCHAR("宗师"),4}},
		{FGameplayTag::RequestGameplayTag(FName("Rarity.Five")),{UTF8_TO_TCHAR("仙品"),UTF8_TO_TCHAR("圣贤"),5}}
	};
}

FRarityContent URarityComponent::GetRarityContent()
{
	return RarityMap[Rarity];
}


