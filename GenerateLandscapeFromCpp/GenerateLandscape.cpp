// write by pto8913

#include "BPFL_GenerateLandscape.h"

#include "EngineUtils.h"
#include "Landscape.h"
#include "LandscapeInfo.h"
#include "LandscapeEditorUtils.h"

bool UBPFL_GenerateLandscape::GenerateLandscape(const UObject* worldContextObject_)
{
	FActorSpawnParameters params;

	params.bDeferConstruction = false;
	params.ObjectFlags = EObjectFlags::RF_NoFlags;
	params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	UWorld* world = worldContextObject_->GetWorld();

	FVector location(0.0f, 0.0f, 0.0f);
	FRotator rotator(0.0f, 0.0f, 0.0f);

	ALandscape* landscape = world->SpawnActor<ALandscape>(location, rotator, params);
	ALandscapeProxy* proxy = Cast<ALandscapeProxy>(landscape);

	int section_size = 63;
	int section_per_component = 1;
	int component_x = 8;
	int component_y = 8;
	int quads_per_component = section_per_component * section_size;
	int size_x = component_x * quads_per_component + 1;
	int size_y = component_y * quads_per_component + 1;
	// 値を入れる。
	TArray<uint16> heightmap;
	heightmap.Init(0, size_x * size_y);
	/*for (int x = 0; x < size_x; ++x) {
		for (int y = 0; y < size_y; ++y) {
			heightmap[y + x * size_y] = x * y;
		}
	}*/

	TArray<FLandscapeImportLayerInfo> infos;
	proxy->Import(FGuid::NewGuid(), 0, 0, size_x - 1, size_y - 1, section_per_component, section_size, heightmap.GetData(), nullptr, infos, ELandscapeImportAlphamapType::Additive);
	return true;
}
