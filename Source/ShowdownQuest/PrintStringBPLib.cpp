// Copyright (c) Meta Platforms, Inc. and affiliates. All rights reserved.


#include "PrintStringBPLib.h"

#if PLATFORM_ANDROID
	#include <android/log.h>
#endif

DEFINE_LOG_CATEGORY_STATIC(LogPrintStringBPLib, Display, All);

void SHOWDOWNQUEST_API UPrintStringBPLib::DebugLog(const FString& logString)
{
#if PLATFORM_ANDROID
	// Duplicated string logic from UE4_LOG. This will output in shipping builds.
	const int MAX_LOG_LENGTH = 4096;
	// not static since may be called by different threads
	wchar_t MessageBuffer[MAX_LOG_LENGTH];

	const TCHAR* SourcePtr = *logString;
	while (*SourcePtr)
	{
		wchar_t* WritePtr = MessageBuffer;
		int32 RemainingSpace = MAX_LOG_LENGTH;
		while (*SourcePtr && --RemainingSpace > 0)
		{
			if (*SourcePtr == TEXT('\n'))
			{
				++SourcePtr;
				break;
			}
			else
			{
				*WritePtr++ = static_cast<wchar_t>(*SourcePtr++);
			}
		}
		*WritePtr = '\0';
		__android_log_print(ANDROID_LOG_INFO, "Showdown", "%ls", MessageBuffer);
	}
#else
	UE_LOG(LogPrintStringBPLib, Display, TEXT("%s"), *logString);
#endif
}
