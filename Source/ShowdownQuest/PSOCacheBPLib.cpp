// Copyright (c) Meta Platforms, Inc. and affiliates. All rights reserved.


#include "PSOCacheBPLib.h"
#include "ShaderPipelineCache.h"

bool SHOWDOWNQUEST_API UPSOCacheBPLib::PSOCacheReady()
{
	uint32 remaining = FShaderPipelineCache::NumPrecompilesRemaining();

	if (remaining > 0)
	{
		UE_LOG(LogTemp, Log, TEXT("PSO Cache %u remaining"), remaining);
		return false;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("PSO Cache ready"));
	}

	return true;
}