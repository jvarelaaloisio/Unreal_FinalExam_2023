// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DoorComp.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREAL_FINAL_2023_API UDoorComp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorComp();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
		class UDataTable* DataTable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
		FName RowName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
		FName CoinTag = "Coin";
	bool IsOpened = false;
	struct FCoinStruct* Row;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);
	UPROPERTY(BlueprintAssignable)
		FDoorEvent OnOpen;
};
