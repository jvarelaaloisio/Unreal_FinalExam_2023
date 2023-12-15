// Fill out your copyright notice in the Description page of Project Settings.


#include "UAttackComp.h"
#include "Components/SphereComponent.h"
#include <UHealthComp.h>

// Sets default values for this component's properties
UUAttackComp::UUAttackComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UUAttackComp::BeginPlay()
{
	Super::BeginPlay();
	if (CollisionComp)
	{
		CollisionComp->OnComponentHit.AddDynamic(this, &UUAttackComp::OnHit);
	}
}


// Called every frame
void UUAttackComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UUAttackComp::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor != nullptr && OtherActor != GetOwner())
	{
		Attack(OtherActor);
	}
	HitComp->SetGenerateOverlapEvents(false);
}

void UUAttackComp::Attack(AActor* OtherActor)
{
	UUHealthComp* healthComp = OtherActor->FindComponentByClass<UUHealthComp>();

	if (healthComp != nullptr)
	{
		healthComp->TakeDamage(AttackPoints);
	}
}
