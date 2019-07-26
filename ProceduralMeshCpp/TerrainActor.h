// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "TerrainActor.generated.h"

class UProceduralMeshComponent;

UCLASS()
class LOL2_API ATerrainActor : public AActor
{
	GENERATED_BODY()

public:
	ATerrainActor(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere)
		int RowX;

	UPROPERTY(EditAnywhere)
		int RowY;

	void CreateTriangle();

	// 頂点群
	TArray<FVector> Vertices;
	// インデックス群
	TArray<int32> Triangles;
	// 法線群
	TArray<FVector> Normals;
	// テクスチャー座標群
	TArray<FVector2D> UV0;
	// 頂点カラー群
	TArray<FLinearColor> vertexColors;
	// 接線群
	TArray<FProcMeshTangent> Tangents;

	UProceduralMeshComponent* mesh;

protected:
	virtual void BeginPlay() override;

	virtual void PostActorCreated() override;

	virtual void PostLoad() override;

public:
	virtual void Tick(float DeltaTime) override;
};
