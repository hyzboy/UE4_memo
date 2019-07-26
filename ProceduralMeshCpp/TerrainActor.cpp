// write by pto8913
#include "TerrainActor.h"
#include "EngineUtils.h"
#include "Runtime/Foliage/Public/InstancedFoliageActor.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

#include <random>

ATerrainActor::ATerrainActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
	//static ConstructorHelpers::FObjectFinder <UMaterialInterface> MyMaterialMeshObj(TEXT("/Game/Materials/Auto_Terrain_Material.Auto_Terrain_Material"));
	//MyMaterial = MyMaterialMeshObj.Object;

	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	RootComponent = mesh;

  	mesh->bUseAsyncCooking = true;
}

void ATerrainActor::PostActorCreated()
{
	Super::PostActorCreated();
	CreateTriangle();
}

void ATerrainActor::PostLoad()
{
	Super::PostLoad();
	CreateTriangle();
}

void ATerrainActor::CreateTriangle() {
  	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> Zrand(0, RowZ);

	for (int y = 0; y < RowY - 1; ++y) {
		for (int x = 0; x < RowX - 1; ++x) {
			Vertices.Add(FVector(x * 100, y * 100, Zrand(mt)));
			UV0.Add(FVector2D(x, y));

			Vertices.Add(FVector(x * 100, (y + 1) * 100, Zrand(mt)));
			UV0.Add(FVector2D(x, y + 1));

			Vertices.Add(FVector((x + 1) * 100, y * 100, Zrand(mt)));
			UV0.Add(FVector2D(x + 1, y));

			Vertices.Add(FVector((x + 1) * 100, y * 100, Zrand(mt)));
			UV0.Add(FVector2D(x + 1, y));

			Vertices.Add(FVector(x * 100, (y + 1) * 100, Zrand(mt)));
			UV0.Add(FVector2D(x, y + 1));

			Vertices.Add(FVector((x + 1) * 100, (y + 1) * 100, Zrand(mt)));
			UV0.Add(FVector2D(x + 1, y + 1));
		}
	}

	int length = Vertices.Num();

	for (int i = 0; i < length; ++i) {
		Triangles.Add(i);
	}

	Normals.Init(FVector(0, 0, 1), length);
	Tangents.Init(FProcMeshTangent(0, -1, 0), length);
	mesh->CreateMeshSection_LinearColor(0, Vertices, Triangles, Normals, UV0, vertexColors, Tangents, true);

	mesh->ContainsPhysicsTriMeshData(true);
	//mesh->SetMaterial(0, MyMaterial);
	mesh->SetBoundsScale(2);
}

void ATerrainActor::BeginPlay() {
	Super::BeginPlay();
}

void ATerrainActor::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}
