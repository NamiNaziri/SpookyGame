// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpookyGamePlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "SpookyGame/SpookyGameCharacter.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "SpookyGamePlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

ASpookyGamePlayerController::ASpookyGamePlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	/*FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior((EMouseLockMode::DoNotLock));
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);*/
}

void ASpookyGamePlayerController::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}


void ASpookyGamePlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		// Setup mouse input events
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASpookyGamePlayerController::OnMove);
	}
}

void ASpookyGamePlayerController::OnMove(const FInputActionValue& Value)
{
	const FVector2D MoveValue = Value.Get<FVector2D>();
	
	const FRotator MovementYawRotation(0, GetControlRotation().Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(MovementYawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(MovementYawRotation).GetUnitAxis(EAxis::Y);
	
	if(APawn* ControlledPawn = GetPawn<APawn>())
	{
		FString FloatAsString = FString::Printf(TEXT("%.2f"),Cast<ASpookyGamePlayerCharacter>(ControlledPawn)->GetCharacterMovement()->GetMaxSpeed());
		UE_LOG(LogTemp,Warning, TEXT("%s"), *(FloatAsString));
		ControlledPawn->AddMovementInput(ForwardDirection, MoveValue.Y);
		ControlledPawn->AddMovementInput(RightDirection, MoveValue.X);
	}
	

	
}
