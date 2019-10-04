// write by pto8913

#include "DestroyLandscape.h"

#include "EngineUtils.h"
#include "Landscape.h"
#include "LandscapeInfo.h"
#include "LandscapeEditorUtils.h"
#include "Kismet/GameplayStatics.h"

bool UDestroyLandscape::DestroyLandscape(const UObject* worldContextObject_) {
	UWorld* world = worldContextObject_->GetWorld();

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(world, ALandscape::StaticClass(), FoundActors);

	for (auto actor : FoundActors) {
		world->DestroyActor(actor);
		return true;
	}
	return false;
}
