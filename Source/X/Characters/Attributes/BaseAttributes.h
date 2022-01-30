// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FatherAttributes.h"
#include "BaseAttributes.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBaseAttributeChange, float, AttributeValue, FName, Name);
/**
 * 
 */
UCLASS()
class X_API UBaseAttributes : public UFatherAttributes
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Base", ReplicatedUsing = OnRep_Body, meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Body;
	ATTRIBUTE_ACCESSORS(UBaseAttributes, Body)

	UPROPERTY(BlueprintReadOnly, Category = "Base", ReplicatedUsing = OnRep_MaxBody, meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxBody;
	ATTRIBUTE_ACCESSORS(UBaseAttributes, MaxBody)

	UPROPERTY(BlueprintReadOnly, Category = "Base", ReplicatedUsing = OnRep_Reiki, meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Reiki;
	ATTRIBUTE_ACCESSORS(UBaseAttributes, Reiki)

	UPROPERTY(BlueprintReadOnly, Category = "Base", ReplicatedUsing = OnRep_MaxReiki, meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxReiki;
	ATTRIBUTE_ACCESSORS(UBaseAttributes, MaxReiki)

	UPROPERTY(BlueprintReadOnly, Category = "Base", ReplicatedUsing = OnRep_Mentality, meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Mentality;
	ATTRIBUTE_ACCESSORS(UBaseAttributes, Mentality)

	UPROPERTY(BlueprintReadOnly, Category = "Base", ReplicatedUsing = OnRep_MaxMentality, meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxMentality;
	ATTRIBUTE_ACCESSORS(UBaseAttributes, MaxMentality)

private:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(BlueprintAssignable, Category = "Character BaseAttributes")
	FBaseAttributeChange OnAttributeChange;

	virtual void PostAttributeChange(const FGameplayAttribute & Attribute,float OldValue,float NewValue) override;

	virtual void PostAttributeBaseChange(const FGameplayAttribute & Attribute,float OldValue,float NewValue) const override;

	UFUNCTION()
	virtual void OnRep_Body(const FGameplayAttributeData& OldBody);
	UFUNCTION()
	virtual void OnRep_MaxBody(const FGameplayAttributeData& OldMaxBody);
	
	UFUNCTION()
	virtual void OnRep_Reiki(const FGameplayAttributeData& OldReiki);
	UFUNCTION()
	virtual void OnRep_MaxReiki(const FGameplayAttributeData& OldMaxReiki);
	
	UFUNCTION()
	virtual void OnRep_Mentality(const FGameplayAttributeData& OldMentality);
	UFUNCTION()
	virtual void OnRep_MaxMentality(const FGameplayAttributeData& OldMaxMentality);
};
