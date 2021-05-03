// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelChanger_Component.h"

// Sets default values for this component's properties
ULevelChanger_Component::ULevelChanger_Component()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULevelChanger_Component::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void ULevelChanger_Component::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void ULevelChanger_Component::OpenLevel(FName levelName)
{
	UGameplayStatics::OpenLevel(GetWorld(), levelName);
}

