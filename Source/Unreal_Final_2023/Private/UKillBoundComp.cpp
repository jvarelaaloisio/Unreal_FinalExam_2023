// Fill out your copyright notice in the Description page of Project Settings.


#include "UKillBoundComp.h"
#include "Components/StaticMeshComponent.h"
#include <UHealthComp.h>

// Sets default values for this component's properties
UUKillBoundComp::UUKillBoundComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UUKillBoundComp::BeginPlay()
{
	Super::BeginPlay();
	if (!MeshComp)
	{
		MeshComp = Cast<UStaticMeshComponent>(GetOwner()->GetComponentByClass(UStaticMeshComponent::StaticClass()));
	}
	MeshComp->OnComponentBeginOverlap.AddDynamic(this, &UUKillBoundComp::OnOverlap);
}

void UUKillBoundComp::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != nullptr && OtherActor != GetOwner())
	{
		UUHealthComp* healthComp = OtherActor->FindComponentByClass<UUHealthComp>();

		if (healthComp != nullptr)
		{
			healthComp->TakeDamage(healthComp->GetHealthPoints());
		}
	}
}
