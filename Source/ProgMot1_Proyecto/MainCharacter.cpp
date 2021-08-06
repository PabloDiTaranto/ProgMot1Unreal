// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	canMove = true;
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMainCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MouseX", this, &AMainCharacter::MouseX);
	PlayerInputComponent->BindAxis("MouseY", this, &AMainCharacter::MouseY);

	//PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMainCharacter::Jump);
}



void AMainCharacter::MoveForward(float f)
{
	if (!canMove) return;
	if (Controller && f != 0) 
	{
		FRotator rot = GetController()->GetControlRotation();
		FRotator myYaw(0, rot.Yaw, 0);
		FVector dir = FRotationMatrix(myYaw).GetUnitAxis(EAxis::X);
		AddMovementInput(dir, f);
	}
}

void AMainCharacter::MoveRight(float f)
{
	if (!canMove) return;
	if (Controller && f != 0) 
	{
		FRotator rot = GetController()->GetControlRotation();
		FRotator myYaw(0, rot.Yaw, 0);
		FVector dir = FRotationMatrix(myYaw).GetUnitAxis(EAxis::Y);
		AddMovementInput(dir, f);	
	}
}

void AMainCharacter::MouseX(float f)
{
	if (!canMove) return;
	AddControllerYawInput(f);
}

void AMainCharacter::MouseY(float f)
{
	if (!canMove) return;
	AddControllerPitchInput(f);
}

void AMainCharacter::SwapMovement(bool newState)
{
	canMove = newState;
}

