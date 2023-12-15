// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UCoinComp.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREAL_FINAL_2023_API UUCoinComp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUCoinComp();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Coin")
		class UDataTable* DataTable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Coin")
		FName KeyName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Coin")
		int Value = 1;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

};
