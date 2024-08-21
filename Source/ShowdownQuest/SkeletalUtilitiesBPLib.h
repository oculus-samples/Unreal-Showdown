// Copyright (c) Meta Platforms, Inc. and affiliates. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SkeletalUtilitiesBPLib.generated.h"

/**
 * 
 */
UCLASS()
class SHOWDOWNQUEST_API USkeletalUtilitiesBPLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Skeletal")
	static void SetCPUSkinning(bool bEnabled, USkeletalMeshComponent * target);
	
};
