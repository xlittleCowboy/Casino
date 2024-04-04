// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Casino : ModuleRules
{
	public Casino(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput",
			"GameplayAbilities", "GameplayTags", "GameplayTasks" });
	}
}
