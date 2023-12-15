#include "ResetCoinsGameInstance.h"
#include "Engine/DataTable.h"
#include "CoinStruct.h"

UResetCoinsGameInstance::UResetCoinsGameInstance()
{
}

void UResetCoinsGameInstance::Init()
{
    Super::Init();

    FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UResetCoinsGameInstance::OnLevelLoaded);
}

void UResetCoinsGameInstance::OnLevelLoaded(const FString& mapName)
{
    // Reset DataTable values upon level load
    ResetDataTableValues();
}

void UResetCoinsGameInstance::ResetDataTableValues()
{

    FCoinStruct* FoundRow = DataTable->FindRow<FCoinStruct>(RowName, "");
    if (FoundRow != nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("Reseting data table"));
        FoundRow->SetQuantity(0);
    }
    // Get a reference to your DataTable and reset values as needed
    // For example:
    // UDataTable* MyDataTable = ...; // Get your data table reference
    // MyDataTable->EmptyTable(); // Clear the table or reset values
}
