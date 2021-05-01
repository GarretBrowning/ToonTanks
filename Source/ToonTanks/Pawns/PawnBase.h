// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

class UCapsuleComponent;

UCLASS()
class TOONTANKS_API APawnBase : public APawn
{
	GENERATED_BODY()

private:

	UPROPERTY()
	UCapsuleComponent* CapsuleComp; // General Collision information for our pawns.
	UPROPERTY()	
	UStaticMeshComponent* BaseMesh; // Tank/A.I. base body
	UPROPERTY()	
	UStaticMeshComponent* TurretMesh; // Turret Mesh for both Tank & A.I.
	UPROPERTY()
	USceneComponent* ProjectileSpawnPoint; // Collection of data to present visual representation of where the projectile spawns from.
 
public:
	// Sets default values for this pawn's properties
	APawnBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
