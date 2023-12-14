// Fill out your copyright notice in the Description page of Project Settings.


#include "UHealthComp.h"
#include "..\Public\UHealthComp.h"

// Sets default values for this component's properties
UUHealthComp::UUHealthComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UUHealthComp::BeginPlay()
{
	Super::BeginPlay();
	HealthPoints = MaxHealthPoints;
	
}


// Called every frame
void UUHealthComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UUHealthComp::TakeDamage(int damagePoints)
{
	ChangeHP(-damagePoints);
}

void UUHealthComp::Heal(int healPoints)
{
	ChangeHP(healPoints);
}

void UUHealthComp::ChangeHP(const int& points)
{
	HealthPoints += points;
	if (HealthPoints > MaxHealthPoints)
		HealthPoints = MaxHealthPoints;
	if (HealthPoints < 0)
		HealthPoints = 0;
	OnHealthPointsChanged.Broadcast(HealthPoints);
	UE_LOG(LogTemp, Log, TEXT("HP: "), HealthPoints);
}

int UUHealthComp::GetHealthPoints()
{
	return HealthPoints;
}

