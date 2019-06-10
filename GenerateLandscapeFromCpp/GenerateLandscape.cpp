// write by pto8913

#include "BPFL_GenerateLandscape.h"

#include "EngineUtils.h"
#include "Landscape.h"
#include "LandscapeInfo.h"
#include "LandscapeEditorUtils.h"

TArray<uint16> heightmap_expand(TArray<uint16> Data, int width, int height, int new_width, int new_height) {
	uint16 *original_data_buf = Data.GetData();
	int data_len = Data.Num();

	TArray<uint16> original_data;
	original_data.Init(0, data_len / 2);

	FMemory::Memcpy(original_data.GetData(), original_data_buf, data_len);

	int offset_x = (new_width - width) / 2;
	int offset_y = (new_height - height) / 2;

	TArray<uint16> new_data = LandscapeEditorUtils::ExpandData(original_data, 0, 0, width - 1, height - 1, -offset_x, -offset_y, new_width - offset_x - 1, new_height - offset_y - 1);

	return new_data;
}

bool UBPFL_GenerateLandscape::GenerateLandscape(const UObject* worldContextObject_)
{
	FActorSpawnParameters params;

	params.bAllowDuringConstructionScript = true;
	params.bDeferConstruction = false;
	params.bNoFail = true;
	params.Instigator = nullptr;
	params.Name = { "aiueo" };
	params.ObjectFlags = EObjectFlags::RF_NoFlags;
	params.OverrideLevel = nullptr;
	params.Owner = nullptr;
	params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	params.Template = nullptr;

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

	TArray<uint16> heightmap;
	heightmap.Init(0, size_x * size_y);
	for (int x = 0; x < size_x; ++x) {
		for (int y = 0; y < size_y; ++y) {
			heightmap[y + x * size_y] = x * y;
		}
	}
	// TArray<uint16> Data = heightmap_expand(heightmap, width, height, section_size * section_per_component * component_y + 1, section_size * section_per_component * component_x + 1);
	TArray<FLandscapeImportLayerInfo> infos;
	proxy->Import(FGuid::NewGuid(), 0, 0, size_x - 1, size_y - 1, section_per_component, section_size, heightmap.GetData(), nullptr, infos, ELandscapeImportAlphamapType::Additive);
	return true;
}
