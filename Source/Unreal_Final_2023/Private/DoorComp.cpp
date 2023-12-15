// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorComp.h"
#include "Engine/DataTable.h"
#include "CoinStruct.h"
#include "UCoinComp.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"

// Sets default values for this component's properties
UDoorComp::UDoorComp()
{
	// Set this component to be initialized when the game starts, and to be ticked e very frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorComp::BeginPlay()
{
	Super::BeginPlay();

	Row = DataTable->FindRow<FCoinStruct>(RowName, "");
}


// Called every frame
void UDoorComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (IsOpened)
		return;
	int quantity = 0;
	if (Row != nullptr)
	{
		quantity = Row->Quantity;
	}

	int TaggedActorQty = 0;
	if (!CoinTag.IsNone())
	{
		if (UWorld* World = GetWorld())
		{
			for (FActorIterator It(World); It; ++It)
			{
				AActor* Actor = *It;
				if (Actor->GetComponentsByClass(UUCoinComp::StaticClass()).Num() > 0)
				{
					TaggedActorQty++;
				}
			}
		}
	}
	if (quantity > 0 && TaggedActorQty <= quantity / 2)
	{
		OnOpen.Broadcast();
		UE_LOG(LogTemp, Log, TEXT("Door opened"));
		IsOpened = true;
	}
	UE_LOG(LogTemp, Log, TEXT("Door: %d - %d"), TaggedActorQty, quantity);
}

