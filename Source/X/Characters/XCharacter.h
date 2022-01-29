// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "X/Abilities/XAbilitySystemComponent.h"
#include "X/Abilities/FatherGameplayAbility.h"
#include "XCharacter.generated.h"

UCLASS(Blueprintable)
class AXCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AXCharacter();

	virtual UXAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character Abilities")
	class UXAbilitySystemComponent* MyAbilitySystemComponent;

	virtual void PossessedBy(AController * NewController) override;

	/*初始化角色属性*/
	UPROPERTY(EditDefaultsOnly, Category = "Character Attribute")
	TSubclassOf<class UGameplayEffect> DefaultAttributes;
	/*初始化角色技能*/
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Character Abilities")
	TArray<TSubclassOf<class UFatherGameplayAbility>> CharacterAbilities;
	/*初始化GE效果*/
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Character Abilities")
	TArray<TSubclassOf<class UGameplayEffect>> StartupEffects;
	/*角色等级*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character Level")
	int32 CharacterLevel=1;

private:
	//初始化属性
	virtual void InitAttributes();
	//添加初始效果
	virtual void AddStartUpEffects();
	//添加初始技能
	virtual void AddCharacterStartupAbilities();
};

