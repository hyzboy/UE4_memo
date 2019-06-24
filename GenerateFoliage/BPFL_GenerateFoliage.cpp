// Fill out your copyright notice in the Description page of Project Settings.

#include "BPFL_GenerateFoliage.h"

#include "EngineUtils.h"
#include "Runtime/Foliage/Public/InstancedFoliageActor.h"

bool UBPFL_GenerateFoliage::GenerateFoliage(const UObject* worldContextObject_) {
	UWorld *world = worldContextObject_->GetWorld();
	TActorIterator<AInstancedFoliageActor> foliageIterator(world);
	AInstancedFoliageActor* foliageActor = *foliageIterator;

	TArray<UInstancedStaticMeshComponent*> components;
	foliageActor->GetComponents<UInstancedStaticMeshComponent>(components);
	
	UInstancedStaticMeshComponent* meshComponent = components[0];

	FTransform transform = FTransform();
	transform.SetLocation(FVector(1000.f, 1000.f, 0.f));
	//transform.SetRotation(FQuat(1,1,45,1));
	meshComponent->AddInstance(transform);
	return true;
}
