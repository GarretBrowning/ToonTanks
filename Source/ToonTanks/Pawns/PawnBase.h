// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

class UCapsuleComponent;
class AProjectileBase;

UCLASS()
class TOONTANKS_API APawnBase : public APawn
{
	GENERATED_BODY()

private:

	// Components:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* CapsuleComp; // General Collision information for our pawns.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))	
	UStaticMeshComponent* BaseMesh; // Tank/A.I. base body
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))	
	UStaticMeshComponent* TurretMesh; // Turret Mesh for both Tank & A.I.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint; // Collection of data to present visual representation of where the projectile spawns from.

	// Variables:
	UPROPERTY(EditAnywhere, BlueprintReadONly, Category = "Projectile Type", meta = (AllowPrivateAccess = "true"));
	TSubclassOf<AProjectileBase> ProjectileClass;
 
public:
	// Sets default values for this pawn's properties
	APawnBase();
	
	void PawnDestroyed();
	virtual void HandleDestruction();

protected:
	void RotateTurret(FVector LookAtTarget);
	void Fire();
};
