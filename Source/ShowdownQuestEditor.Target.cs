// Copyright (c) Meta Platforms, Inc. and affiliates. All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ShowdownQuestEditorTarget : TargetRules
{
	public ShowdownQuestEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.AddRange( new string[] { "ShowdownQuest" } );
	}
}
