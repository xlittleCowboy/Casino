// Copyright Renaissance. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CasinoCharacter.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class CASINO_API AEnemyCharacter : public ACasinoCharacter
{
	GENERATED_BODY()

public:
	AEnemyCharacter();

	virtual void PossessedBy(AController* NewController) override;

protected:
	virtual void BeginPlay() override;

	void HealthChanged(const FOnAttributeChangeData& Data);

public:
	virtual void Tick(float DeltaTime) override;
};
