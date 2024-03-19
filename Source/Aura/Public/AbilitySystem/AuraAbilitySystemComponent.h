// Copyright Morph

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AuraAbilitySystemComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FEffectAssetTags, const FGameplayTagContainer& /*AssetTags*/);

/**
 * 
 */
UCLASS()
class AURA_API UAuraAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:
	FEffectAssetTags EffectAssetTags;
	
	void AbilityActorInfoSet();

	void AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities);
	
	void AbilityInputTagHeld(const FGameplayTag InputTag);
	void AbilityInputTagReleased(const FGameplayTag InputTag);
protected:
	// 解决拾取actor时候只有server才有popup information, 此时ClientEffectApplied 将被server 调用，被client execute
	UFUNCTION(Client, Reliable)
	void ClientEffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle);
	
};
