// Fill out your copyright notice in the Description page of Project Settings.


#include "Chest.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AChest::AChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AChest::BeginPlay()
{
	Super::BeginPlay();
}


void AChest::SpawnCoins()
{
    if (!CoinClass)
    {
        UE_LOG(LogTemp, Warning, TEXT("CoinClass is not set!"));
        return;
    }

    FVector SpawnLocation = GetActorLocation() + FVector(0.0f, 0.0f, 100.0f);
    FRotator SpawnRotation = FRotator::ZeroRotator;
    AActor* SpawnedCoin = GetWorld()->SpawnActor<AActor>(CoinClass, SpawnLocation, SpawnRotation);
}