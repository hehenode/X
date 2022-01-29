// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "FatherGameplayAbility.generated.h"

UENUM(BlueprintType)
enum class EXZAbilityInputID : uint8
{
	NONE,
	CONFIRM,
	CANCEL,
	ABILITY1,
	ABILITY2,
	ABILITY3,
	ABILITY4,
	ABILITY5,
	ABILITY6,
	ABILITY7,
	ABILITY8,
	ABILITY9,
	ABILITY10,
};
/**
 * 
 */
UCLASS()
class X_API UFatherGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UFatherGameplayAbility();
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
	bool bAutoActivate = false;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
	FString AbilityName;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
	int32 AbilityLevel=1;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
	EXZAbilityInputID InputID = EXZAbilityInputID::NONE;

	UFUNCTION()
	void SetAbilityLevel(int32 Level) const;

private:
	virtual void OnAvatarSet(const FGameplayAbilityActorInfo * ActorInfo,const FGameplayAbilitySpec & Spec) override;
};

