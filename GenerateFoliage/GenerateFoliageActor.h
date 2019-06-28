// write by pto8913

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyLevelScriptActor.generated.h"

UCLASS()
class LOL_API GenerateFoliageActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	GenerateFoliageActor(const FObjectInitializer& ObjectInitializer);


	virtual void BeginPlay() override;


	UStaticMesh* MyStaticMesh;
};
