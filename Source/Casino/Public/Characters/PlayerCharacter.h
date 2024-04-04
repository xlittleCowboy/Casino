// Copyright Renaissance. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CasinoCharacter.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class CASINO_API APlayerCharacter : public ACasinoCharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
