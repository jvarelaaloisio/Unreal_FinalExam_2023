// Fill out your copyright notice in the Description page of Project Settings.

#include "URunBehaviorTreeComp.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/PawnSensingComponent.h"

UURunBehaviorTreeComp::UURunBehaviorTreeComp()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UURunBehaviorTreeComp::BeginPlay()
{
	Super::BeginPlay();
	AActor* Owner = GetOwner();
	if (!Owner)
	{
		UE_LOG(LogTemp, Error, TEXT("Owner is null!"));
		return;
	}
	AAIController* AIController = Cast<AAIController>(Owner->GetInstigatorController());
	if (!AIController)
		return;
	auto bb_comp = Owner->GetComponentByClass(UBlackboardComponent::StaticClass());
	blackboard = Cast<UBlackboardComponent>(bb_comp);
	if (blackboard)
	{
		AIController->UseBlackboard(blackboard->GetBlackboardAsset(), blackboard);
		blackboard->SetValueAsObject(TargetBlackBoardKey, Target);
		auto ps_comp = Owner->GetComponentByClass(UPawnSensingComponent::StaticClass());
		PawnSensing = Cast<UPawnSensingComponent>(ps_comp);
	}
	if (BehaviorTree)
		AIController->RunBehaviorTree(BehaviorTree);
}

void UURunBehaviorTreeComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	SetSight();
}

void UURunBehaviorTreeComp::SetSight()
{
	if (blackboard && PawnSensing)
	{
		bool CanSeeTarget = PawnSensing->HasLineOfSightTo(Target);
		blackboard->SetValueAsBool(CanSeeTargetKey, CanSeeTarget);
		auto value = blackboard->GetValueAsBool(CanSeeTargetKey);

		AAIController* AIController = Cast<AAIController>(GetOwner()->GetInstigatorController());
		if (AIController)
			AIController->RunBehaviorTree(BehaviorTree);
	}
}