// Copyright Renaissance. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CasinoPlayerController.generated.h"

class APlayerCharacter;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class CASINO_API ACasinoPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<APlayerCharacter> ControlledPlayerCharacter;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TSet<UInputMappingContext*> DefaultMappingContexts;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* MoveAction;

	virtual void OnPossess(APawn* InPawn) override;
	
	void Move(const FInputActionValue& Value);
	void Jump(const FInputActionValue& Value);
	void StopJumping(const FInputActionValue& Value);

public:
	virtual void SetupInputComponent() override;
};
