// write by pto8913
// 古いものから順番に消されるので注意して下さい。
// note : that the oldest ones will be deleted in order.

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
