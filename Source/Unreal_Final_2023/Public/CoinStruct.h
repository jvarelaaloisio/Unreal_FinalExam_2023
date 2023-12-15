#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CoinStruct.generated.h"

USTRUCT(BlueprintType)
struct FCoinStruct : public FTableRowBase
{
    GENERATED_BODY()

public:
    FCoinStruct();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CoinData")
        int Quantity;

    void Add(int Qty);
    void SetQuantity(int newValue);
};