// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GenerateFoliageActor.generated.h"

UCLASS()
class MYPROJECT2_API AGenerateFoliageActor : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AMyLevelScriptActor(const FObjectInitializer& ObjectInitializer);


	virtual void BeginPlay() override;


	UStaticMesh* MyStaticMesh;
};
