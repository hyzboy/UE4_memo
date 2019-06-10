// write by pto8193

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFL_GenerateLandscape.generated.h"

UCLASS()
// change your project name from "MYPROJECT2_API"
class MYPROJECT2_API UBPFL_GenerateLandscape : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = LandscapeTest, meta = (HidePin = "worldContextObject_", DefaultToSelf = "worldContextObject_"))
		static bool GenerateLandscape(const UObject* worldContextObject_);

};
