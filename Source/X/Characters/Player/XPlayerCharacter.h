// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "X/Characters/XCharacter.h"
#include "X/Characters/Attributes/BaseAttributes.h"
#include "XPlayerCharacter.generated.h"

USTRUCT(BlueprintType)
struct FReleaseTarget
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FVector TargetLocation = FVector(NAN);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	AActor* TargetActor = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability Factor")
	TSubclassOf<UGameplayAbility> FireAbility;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAttributeChange, float, AttributeValue, FName, Name);

UCLASS()
class X_API AXPlayerCharacter : public AXCharacter
{
	GENERATED_BODY()

public:
	AXPlayerCharacter();
	
	virtual void SetupPlayerInputComponent(class UInputComponent * PlayerInputComponent) override;

	/*释放技能所需信息*/
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Character Abilities")
	FReleaseTarget ReleaseTarget;
	
	UPROPERTY(BlueprintAssignable, Category = "Character Attribute")
	FAttributeChange OnAttributeChange;

	UFUNCTION(BlueprintCallable)
		void InitAbilityFactor();

	UFUNCTION(BlueprintCallable)
		void UpdateAbilityFactor();

	UFUNCTION(BlueprintCallable)
		void StartFireAbility();

private:
	void OnAttrUpdated(const FOnAttributeChangeData& Data) const;

};

