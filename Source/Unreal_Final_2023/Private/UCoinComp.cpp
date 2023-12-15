// Fill out your copyright notice in the Description page of Project Settings.


#include "UCoinComp.h"
#include "Engine/DataTable.h"
#include "CoinStruct.h"

// Sets default values for this component's properties
UUCoinComp::UUCoinComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UUCoinComp::BeginPlay()
{
	Super::BeginPlay();
	auto row = DataTable->FindRow<FCoinStruct>(KeyName, "");
	if (row != nullptr)
	{
		row->Add(Value);
	}
}