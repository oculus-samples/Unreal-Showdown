// Copyright (c) Meta Platforms, Inc. and affiliates. All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ShowdownQuestTarget : TargetRules
{
	public ShowdownQuestTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.AddRange( new string[] { "ShowdownQuest" } );
	}
}
