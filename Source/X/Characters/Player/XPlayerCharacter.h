// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "X/Characters/XCharacter.h"
#include "X/Characters/Attributes/BaseAttributes.h"
#include "XPlayerCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAttributeChange, float, AttributeValue, FName, Name);

UCLASS()
class X_API AXPlayerCharacter : public AXCharacter
{
	GENERATED_BODY()

public:
	AXPlayerCharacter();
	
	virtual void SetupPlayerInputComponent(class UInputComponent * PlayerInputComponent) override;
	
	UPROPERTY(BlueprintAssignable, Category = "Character Attribute")
	FAttributeChange OnAttributeChange;

private:
	void OnAttrUpdated(const FOnAttributeChangeData& Data) const;

};

