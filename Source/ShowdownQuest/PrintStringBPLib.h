// Copyright (c) Meta Platforms, Inc. and affiliates. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PrintStringBPLib.generated.h"

/**
 * 
 */
UCLASS()
class SHOWDOWNQUEST_API UPrintStringBPLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "AAA")
	static void DebugLog(const FString& logString);
	
};
