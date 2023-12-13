// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "URunBehaviorTreeComp.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREAL_FINAL_2023_API UURunBehaviorTreeComp : public UActorComponent
{
	GENERATED_BODY()

public:	
	UURunBehaviorTreeComp();
	UPROPERTY(EditAnywhere, Category = "AI")
		class UBehaviorTree* BehaviorTree;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		class AActor* Target;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		FName TargetBlackBoardKey = "TargetActor";
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		FName CanSeeTargetKey = "CanSeeTarget";
	class UPawnSensingComponent* PawnSensing;
	class UBlackboardComponent* blackboard;

protected:
	virtual void BeginPlay() override;
	void SetSight();

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
