// Copyright (c) Meta Platforms, Inc. and affiliates. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PSOCacheBPLib.generated.h"

/**
 * 
 */
UCLASS()
class SHOWDOWNQUEST_API UPSOCacheBPLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "AAA")
	static bool PSOCacheReady();
};
