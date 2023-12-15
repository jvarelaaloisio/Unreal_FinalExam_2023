// Fill out your copyright notice in the Description page of Project Settings.


#include "ULedgeGrabComp.h"
#include "GameFramework/Character.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UULedgeGrabComp::UULedgeGrabComp()
{
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UULedgeGrabComp::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UULedgeGrabComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    TryGrabLedge();
}

void UULedgeGrabComp::TryGrabLedge()
{
    FVector Start = GetOwner()->GetActorLocation();
    FVector End = Start + (GetOwner()->GetActorForwardVector() * 200.0f);

    FHitResult HitResult;
    FCollisionQueryParams TraceParams(FName(TEXT("LedgeTrace")), true, GetOwner());

    bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, TraceParams);

    if (bHit)
    {
        FVector HitLocation = HitResult.ImpactPoint;
        FVector TraceStart = HitLocation + FVector(0.0f, 0.0f, 1000.0f);
        FVector TraceEnd = HitLocation - FVector(0.0f, 0.0f, 200.0f);

        FHitResult FloorHitResult;
        bool bFloorHit = GetWorld()->LineTraceSingleByChannel(
            FloorHitResult,
            TraceStart,
            TraceEnd,
            ECC_Visibility,
            TraceParams
        );

        if (bFloorHit)
        {
            FVector NewLocation = FloorHitResult.ImpactPoint + FVector(0.0f, 0.0f, 10.0f);
            GetOwner()->SetActorLocation(NewLocation);

        }
    }
}