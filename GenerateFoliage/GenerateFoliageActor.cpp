// Fill out your copyright notice in the Description page of Project Settings.

#include "MyLevelScriptActor.h"
#include "EngineUtils.h"
#include "Runtime/Foliage/Public/InstancedFoliageActor.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

AMyLevelScriptActor::AMyLevelScriptActor(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer){
	static ConstructorHelpers::FObjectFinder <UStaticMesh> MyMeshObj(TEXT("/Game/ScotsPine_01/ScotsPine_01.ScotsPine_01"));
	MyStaticMesh = MyMeshObj.Object;
}

void AMyLevelScriptActor::BeginPlay(){
	Super::BeginPlay();

	TActorIterator<AInstancedFoliageActor> foliageIterator(GetWorld());
	AInstancedFoliageActor* foliageActor = *foliageIterator;

	UInstancedStaticMeshComponent* meshComponent;

	//if you already have foliage in your level, you just need to get the right component, one is created for each type
	TArray<UInstancedStaticMeshComponent*> components;
	foliageActor->GetComponents<UInstancedStaticMeshComponent>(components);
	if (components.Num() > 0)
		meshComponent = components[0];


	//If you havent, you need to create the instanced static mesh component too
	else
	{
		meshComponent = NewObject<UInstancedStaticMeshComponent>(foliageActor, UInstancedStaticMeshComponent::StaticClass(), NAME_None, RF_Transactional);
		meshComponent->AttachToComponent(foliageActor->GetRootComponent(), FAttachmentTransformRules::KeepWorldTransform);
		meshComponent->SetStaticMesh(MyStaticMesh);
		meshComponent->RegisterComponent();
	}



	//Now you just need to add instances to component, this example crate 2500 instances
	FTransform transform = FTransform();
	for (int32 x = 0; x < 50; x++)
	{
		for (int32 y = 0; y < 50; y++)
		{
			transform.SetLocation(FVector(1000.f * x, 1000.f * y, 0.f));
			meshComponent->AddInstance(transform);
		}
	}
}

