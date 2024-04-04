// Copyright Renaissance. All Rights Reserved.

#include "Player/CasinoPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Characters/PlayerCharacter.h"
#include "UserSettings/EnhancedInputUserSettings.h"

void ACasinoPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (const auto* Mapping : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(Mapping, 0);
		}
	}

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent)) {
		
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACasinoPlayerController::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACasinoPlayerController::StopJumping);

		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACasinoPlayerController::Move);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("'%s' Failed to find an Enhanced Input component!"), *GetNameSafe(this));
	}
}

void ACasinoPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	ControlledPlayerCharacter = CastChecked<APlayerCharacter>(InPawn);
}

void ACasinoPlayerController::Move(const FInputActionValue& Value)
{
	if (!ControlledPlayerCharacter)
	{
		return;
	}

	const FVector2D MovementVector = Value.Get<FVector2D>();
	
	const FVector ForwardDirection = FVector(1.0f, 1.0f, 0.0f);
	const FVector RightDirection = FVector(-1.0f, 1.0f, 0.0f);

	ControlledPlayerCharacter->AddMovementInput(ForwardDirection, MovementVector.X);
	ControlledPlayerCharacter->AddMovementInput(RightDirection, MovementVector.Y);
}

void ACasinoPlayerController::Jump(const FInputActionValue& Value)
{
	if (!ControlledPlayerCharacter)
	{
		return;
	}

	ControlledPlayerCharacter->Jump();
}

void ACasinoPlayerController::StopJumping(const FInputActionValue& Value)
{
	if (!ControlledPlayerCharacter)
	{
		return;
	}

	ControlledPlayerCharacter->StopJumping();
}
