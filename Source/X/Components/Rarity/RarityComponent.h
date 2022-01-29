// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTags/Classes/GameplayTagContainer.h"
#include "RarityComponent.generated.h"

USTRUCT(BlueprintType)
struct FRarityContent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly , Category="Rarity")
	FName ThingRarity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly , Category="Rarity")
	FName MonsterRarity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly , Category="Rarity")
	int32 RaritySize;
};
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class X_API URarityComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	URarityComponent();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameplayTag")
	FGameplayTag Rarity;
	
	UFUNCTION(BlueprintCallable)
	FRarityContent GetRarityContent();

private:
	TMap<FGameplayTag, FRarityContent> RarityMap;
};
