// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UHealthComp.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREAL_FINAL_2023_API UUHealthComp : public UActorComponent
{
	GENERATED_BODY()

public:	
	UUHealthComp();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HP")
		int MaxHealthPoints = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HP")
		int HealthPoints = 100;

protected:
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable, Category = "HP")
	void TakeDamage(int damagePoints);
	UFUNCTION(BlueprintCallable, Category = "HP")
	void Heal(int healPoints);
	void ChangeHP(const int& healPoints);
	UFUNCTION(BlueprintPure, Category = "HP")
	int GetHealthPoints();
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHPEvent, int, newHP);

	UPROPERTY(BlueprintAssignable)
		FHPEvent OnHealthPointsChanged;
};
