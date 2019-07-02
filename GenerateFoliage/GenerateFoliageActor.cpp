// write by pto

#include "GenerateFoliageActor.h"
#include "EngineUtils.h"
#include "Runtime/Foliage/Public/InstancedFoliageActor.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

AGenerateFoliageActor::AGenerateFoliageActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
	static ConstructorHelpers::FObjectFinder <UStaticMesh> MyMeshObj(TEXT("Your object path"));
	MyStaticMesh = MyMeshObj.Object;
}

void AGenerateFoliageActor::BeginPlay() {
	Super::BeginPlay();

	TActorIterator<AInstancedFoliageActor> foliageIterator(GetWorld());
	AInstancedFoliageActor* foliageActor = *foliageIterator;

	UInstancedStaticMeshComponent* meshComponent;

	TArray<UInstancedStaticMeshComponent*> components;
	foliageActor->GetComponents<UInstancedStaticMeshComponent>(components);
	
	if (components.Num() > 0)
		// If already exists foliage in your world
		meshComponent = components[0];
	else
	{
		// Select new object
		meshComponent = NewObject<UInstancedStaticMeshComponent>(foliageActor, UInstancedStaticMeshComponent::StaticClass(), NAME_None, RF_Transactional);
		meshComponent->AttachToComponent(foliageActor->GetRootComponent(), FAttachmentTransformRules::KeepWorldTransform);
		meshComponent->SetStaticMesh(MyStaticMesh);
		meshComponent->RegisterComponent();
	}
	FTransform transform = FTransform();
	/*
	// You do not need to write SetScale3D
	transform.SetLocation(FVector(0.f, 0.f, 20.f));
	transform.SetScale3D(FVector(0.5f, 0.5f, 0.5f));
	meshComponent->AddInstance(transform);
	*/
	for (int32 x = 0; x < 5; x++)
	{
		for (int32 y = 0; y < 5; y++)
		{
			transform.SetLocation(FVector(1000.f * x, 1000.f * y, 0.f));
			transform.SetScale3D(FVector(0.5f, 0.5f, 0.5f));
			meshComponent->AddInstance(transform);
		}
	}
}

