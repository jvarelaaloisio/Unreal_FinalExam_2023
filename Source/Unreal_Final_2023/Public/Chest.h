// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Chest.generated.h"

UCLASS()
class UNREAL_FINAL_2023_API AChest : public AActor
{
	GENERATED_BODY()
	
public:	
	AChest();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Chest")
		TSubclassOf<AActor> CoinClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "Chest")
	void SpawnCoins();
};
