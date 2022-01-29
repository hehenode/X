// Fill out your copyright notice in the Description page of Project Settings.


#include "XMonsterCharacter.h"

AXMonsterCharacter::AXMonsterCharacter()
{
	MyAbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
}