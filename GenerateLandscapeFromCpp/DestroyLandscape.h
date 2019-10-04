// write by pto8913

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DestroyLandscape.generated.h"

UCLASS()
class MYPROJECT2_API UDestroyLandscape : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = FoliageTest, meta = (HidePin = "worldContextObject_", DefaultToSelf = "worldContextObject_"))
		static bool DestroyLandscape(const UObject* worldContextObject_);
	
};
