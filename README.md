# Showdown on Meta Quest

<img src="showdown.png">

Showdown on Meta Quest is a port of the PC VR demo originally released for Oculus Rift. It is a helpful example of how to optimize a PC VR application to run smoothly on Quest 2, Quest Pro and Quest 3 mobile renderers, and demonstrates how to integrate [Application SpaceWarp](https://developers.meta.com/horizon/documentation/unreal/unreal-asw/#how-to-enable-appsw-in-app) for a substantial performance boost. Showdown runs at a consistent 90 FPS on Quest 2, Quest 3 and Quest Pro.

Showdown for Quest is also available on [Horizon Store](https://www.meta.com/en-gb/experiences/showdown/4750714098359250/) as a playable apk.

## Documentation

**Engine**<br>
Showdown for Quest depends on the [Oculus fork of UE 5.4 - v68](https://github.com/Oculus-VR/UnrealEngine/tree/oculus-5.4.3-release-1.100.0-v68.0) as it includes App SpaceWarp and the Vulkan mobile tonemap subpass.

**Setup**<br>
First, ensure you have Git LFS installed by running this command:
```sh
git lfs install
```

Then, clone this repo using the "Code" button above, or this command:
```sh
git clone https://github.com/oculus-samples/Unreal-Showdown.git
```

The Oculus Unreal fork will give you the most up to date integration of Oculus features. However, you must build the editor from its source.

1. [Get access to the Unreal source code](https://developers.meta.com/horizon/documentation/unreal/unreal-building-ue4-from-source/#prerequisites)
2. [Clone the `oculus-5.4-68` branch of the Oculus fork](https://github.com/Oculus-VR/UnrealEngine/tree/oculus-5.4.3-release-1.100.0-v68.0)
3. [Install Visual Studio](https://developers.meta.com/horizon/documentation/unreal/unreal-building-ue4-from-source/#to-download-and-build-unreal-engine)
4. Open a command prompt in the root of the Unreal, then run this command:
```sh
.\GenerateProjectFiles.bat -Game Showdown -Engine "<full path to Unreal-Showdown directory>\Showdown.uproject"
```
5. Open the `Showdown.sln` file that has been generated in the `Unreal-Showdown` directory.
6. Set `Showdown` as the start-up project and `Development Editor` as the configuration.
7. Hit `F5` to build and debug the project (and the engine).

**Bundled PSO cache creation**<br>
In order to avoid CPU stalls caused by Pipeline State Object creation at runtime, Epic provides [tools to generate PSO caches in advance](https://dev.epicgames.com/documentation/en-us/unreal-engine/manually-creating-bundled-pso-caches-in-unreal-engine) which can then be bundled in packaged builds.

We have simplified this process through the `GeneratePSOCache.bat` script. In order to use it, follow these steps:

1. Push a build to your device of choice, this build will be used to discover new PSOs.
2. If opened, close the Showdown app on the device.
3. Run `GeneratePSOCache.bat <full path to your UE root>`.
4. The script will automatically launch the application with the required parameters to collect PSOs.
5. Wait for the showcase to complete several times, change the graphics settings to ensure full pipeline coverage (for instance, changing the View Effects Quality generates new PSOs for most static meshes in the scene).
6. Close the application as usual, and press any key in the console to let the script generate the required PSO cache files (recorded cache, stable shader key files).
7. Rebuild the application, the engine will automatically bundle the generated PSO cache.

**Controls**<br>
- Render Settings Menu Open/Close - B
- Menu Up - Right Trigger
- Menu Down - Right Grip Trigger
- Toggle Menu Option - A
- Head Lock Mode - Right Stick Click

**License**<br>
Showdown is distributed under the Unreal Engine EULA. See [LICENSE](LICENSE)<br>
https://www.unrealengine.com/en-US/eula/publishing

**Tools**<br>
Following are the tools used throughout the project:
- [Meta Quest Developer Hub (MQDH)](https://developers.meta.com/horizon/downloads) - The main tool for working with Meta Quest headsets
- [Oculus OVR Metrics](https://developers.meta.com/horizon/documentation/unity/ts-odh-logs-metrics/) - Overlay live metrics in the headset
- [RenderDoc for Oculus](https://developers.meta.com/horizon/downloads/package/renderdoc-oculus/) - GPU frame captures and profiling
- [Snapdragon Profiler](https://developer.qualcomm.com/software/snapdragon-profiler) - More in-depth hardware profiling
- [Unreal Session FrontEnd Profiler](https://docs.unrealengine.com/4.27/en-US/TestingAndOptimization/PerformanceAndProfiling/Profiler/) - Engine profiling
- [Unreal Insights](https://docs.unrealengine.com/4.27/en-US/TestingAndOptimization/PerformanceAndProfiling/UnrealInsights/Overview/) - More detailed engine profiling


**References**<br>
Following are references used throughout the project:
- [Unreal documentation](https://docs.unrealengine.com/en-US/index.html)
- [Meta documentation](https://developers.meta.com/horizon/documentation/unreal/unreal-engine/)
- ["How Drifter Optimized & Delivered Robo Recall for Oculus Quest | Unreal Dev Days 2019"](https://www.youtube.com/watch?v=o-6EMTjzvns)
