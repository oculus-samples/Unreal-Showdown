// Copyright (c) Meta Platforms, Inc. and affiliates. All rights reserved.

using UnrealBuildTool;

public class ShowdownQuest : ModuleRules
{
	public ShowdownQuest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "RenderCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
		
		if (Target.Platform == UnrealTargetPlatform.Android  && Target.Configuration == UnrealTargetConfiguration.Shipping)
		{
			var manifestFile = System.IO.Path.Combine(ModuleDirectory, "UpdatePermissions.xml");
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", manifestFile);
        }
	}
}
