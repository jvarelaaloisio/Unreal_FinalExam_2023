// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UKillBoundComp.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREAL_FINAL_2023_API UUKillBoundComp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUKillBoundComp();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kill Bound")
		class UStaticMeshComponent* MeshComp;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
