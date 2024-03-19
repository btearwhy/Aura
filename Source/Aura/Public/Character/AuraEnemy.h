// Copyright Morph

#pragma once

#include "CoreMinimal.h"
#include "AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
public:
	AAuraEnemy();

	/*Enemy Interface*/
	void HighlightActor() override;
	void UnHighlightActor() override;

	/*Combat Interface*/
	virtual int32 GetPlayerLevel() override;
protected:
	virtual void BeginPlay() override;
	
	void InitAbilityActorInfo() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Class Defaults")
	int32 Level = 1;
};
