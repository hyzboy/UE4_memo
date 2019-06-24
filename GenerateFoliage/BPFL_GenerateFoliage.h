// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFL_GenerateFoliage.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API UBPFL_GenerateFoliage : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = FoliageTest, meta = (HidePin = "worldContextObject_", DefaultToSelf = "worldContextObject_"))
		static bool GenerateFoliage(const UObject* worldContextObject_);
	
};
