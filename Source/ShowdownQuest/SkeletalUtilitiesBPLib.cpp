// Copyright (c) Meta Platforms, Inc. and affiliates. All rights reserved.


#include "SkeletalUtilitiesBPLib.h"
#include "Components/SkeletalMeshComponent.h" 

#if PLATFORM_ANDROID
	#include <android/log.h>
#endif

DEFINE_LOG_CATEGORY_STATIC(LogPrintStringBPLib, Display, All);

void SHOWDOWNQUEST_API USkeletalUtilitiesBPLib::SetCPUSkinning(bool bEnabled, USkeletalMeshComponent * target)
{
	if (!target)
		return;

	target->SetCPUSkinningEnabled(bEnabled, true);
}
