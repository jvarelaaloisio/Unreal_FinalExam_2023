#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ResetCoinsGameInstance.generated.h"

UCLASS()
class UNREAL_FINAL_2023_API UResetCoinsGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    UResetCoinsGameInstance();
    void ResetDataTableValues();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
		class UDataTable* DataTable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
		FName RowName;

protected:
    // Bind level loaded event
    virtual void Init() override;

    // Function to handle level loaded event
    UFUNCTION()
        void OnLevelLoaded(const FString& mapName);
};
