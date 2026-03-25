![Showdown Banner](./showdown.png "Showdown")

# Showdown on Meta Quest

Showdown on Meta Quest is a port of the PC VR demo originally released for Oculus Rift. It is a helpful example of how to optimize a PC VR application to run smoothly on Quest 2, Quest Pro and Quest 3 mobile renderers, and demonstrates how to integrate [Application SpaceWarp](https://developers.meta.com/horizon/documentation/unreal/unreal-asw/#how-to-enable-appsw-in-app) for a substantial performance boost. Showdown runs at a consistent 90 FPS on Quest 2, Quest 3 and Quest Pro.

Showdown for Quest is also available on [Horizon Store](https://www.meta.com/en-gb/experiences/showdown/4750714098359250/) as a playable application.

## Project Description

This project demonstrates how to optimize a PC VR application for Meta Quest mobile renderers, showcasing Application SpaceWarp integration and mobile rendering optimizations. It provides a practical example of achieving consistent 90 FPS performance across Quest 2, Quest Pro, and Quest 3 devices.

## How to Run the Project in Unreal Engine

**NOTE:** Use the Meta Quest fork of Unreal Engine to run this project. See <a href="#Dependencies">Dependencies</a> for details.

1. Ensure you have the project configured with the Oculus fork of Unreal Engine.
2. Use *Unreal Engine 5.4* with the Oculus v68 integration.
3. Open a command prompt in the Unreal root directory and run:
```sh
.\GenerateProjectFiles.bat -Game Showdown -Engine "<full path to Unreal-Showdown directory>\Showdown.uproject"
```
4. Open `Showdown.sln` in the `Unreal-Showdown` directory.
5. Set `Showdown` as the startup project and `Development Editor` as the configuration.
6. Press `F5` to build and debug the project and engine.
7. Load the Showdown project.
8. To test in the Editor, use Quest Link:

    <details>
      <summary><b>Quest Link</b></summary>

    - Enable Quest Link:
        - Put on your headset, open "Quick Settings," and select "Quest Link" (or "Quest Air Link" if using Air Link).
        - Choose your desktop from the list and select "Launch." This starts the Quest Link app, letting you control your desktop from the headset.
    - With the headset on, select "Desktop" from the control panel to view your desktop in VR.
    - In Unreal, change Play Mode to "VR Preview" using the button with three stacked dots in the main toolbar.
    - The application will launch automatically on your headset.
    </details>

## Controls

- Render Settings Menu Open/Close - B
- Menu Up - Right Trigger
- Menu Down - Right Grip Trigger
- Toggle Menu Option - A
- Head Lock Mode - Right Stick Click

## Dependencies

This project requires the Oculus fork of Unreal Engine 5.6 - v81, available [here](https://github.com/Oculus-VR/UnrealEngine/releases/tag/oculus-5.6.0-release-1.113.0-v81.0) as it includes App SpaceWarp and the Vulkan mobile tonemap subpass.
*NOTE:* Access requires [Epic's GitHub access](https://www.unrealengine.com/en-US/ue-on-github).

To test this project in Unreal Engine, you also need:

- [Meta Quest Developer Hub (MQDH)](https://developers.meta.com/horizon/downloads/unreal)
- [Meta Quest Link app](https://www.meta.com/quest/setup/)

### Required Minimal Version

The project depends on the Oculus fork of UE 5.4 - v68 which includes critical features like Application SpaceWarp.

### Oculus Unreal Fork

The Oculus Unreal fork provides the latest Oculus feature integration. You must build the editor from source:

1. [Get access to Unreal source code](https://developers.meta.com/horizon/documentation/unreal/unreal-building-ue4-from-source/#prerequisites).
2. [Clone the `oculus-5.6-81` branch](https://github.com/Oculus-VR/UnrealEngine/tree/oculus-5.6.0-release-1.113.0-v81.0).
3. [Install Visual Studio](https://developers.meta.com/horizon/documentation/unreal/unreal-building-ue4-from-source#download-and-build-unreal-engine).

## Getting the Code

First, install Git LFS by running:

```sh
git lfs install
```

Then clone the repository using the "Code" button above or this command:

```sh
git clone https://github.com/oculus-samples/Unreal-Showdown.git
```

## PSO Cache Generation

In order to avoid CPU stalls caused by Pipeline State Object creation at runtime, Epic provides [tools to generate PSO caches in advance](https://dev.epicgames.com/documentation/en-us/unreal-engine/manually-creating-bundled-pso-caches-in-unreal-engine) which can then be bundled in packaged builds.

We have simplified this process through the `GeneratePSOCache.bat` script. To use it, follow these steps:

1. Push a build to your device of choice, this build will be used to discover new PSOs.
2. If opened, close the Showdown app on the device.
3. Run `GeneratePSOCache.bat <full path to your UE root>`.
4. The script will automatically launch the application with the required parameters to collect PSOs.
5. Wait for the showcase to complete several times, change the graphics settings to ensure full pipeline coverage (for instance, changing the View Effects Quality generates new PSOs for most static meshes in the scene).
6. Close the application as usual, and press any key in the console to let the script generate the required PSO cache files (recorded cache, stable shader key files).
7. Rebuild the application, the engine will automatically bundle the generated PSO cache.

## Tools

Following are the tools used throughout the project:

- [Meta Quest Developer Hub (MQDH)](https://developers.meta.com/horizon/downloads/unreal) - The main tool for working with Meta Quest headsets
- [Oculus OVR Metrics](https://developers.meta.com/horizon/documentation/unreal/ts-mqdh-logs-metrics/) - Overlay live metrics in the headset
- [RenderDoc for Oculus](https://developers.meta.com/horizon/downloads/package/renderdoc-oculus/) - GPU frame captures and profiling
- [Snapdragon Profiler](https://www.qualcomm.com/developer/software/snapdragon-profiler) - More in-depth hardware profiling
- [Unreal Session FrontEnd Profiler](https://dev.epicgames.com/documentation/en-us/unreal-engine/profiler-tool-reference?application_version=4.27) - Engine profiling
- [Unreal Insights](https://dev.epicgames.com/documentation/en-us/unreal-engine/unreal-insights-overview?application_version=4.27) - More detailed engine profiling

## References

Following are references used throughout the project:

- [Unreal documentation](https://dev.epicgames.com/documentation/en-us/unreal-engine/unreal-engine-5-6-documentation?application_version=5.6)
- [Meta documentation](https://developers.meta.com/horizon/documentation/unreal/unreal-engine/)
- ["How Drifter Optimized & Delivered Robo Recall for Oculus Quest | Unreal Dev Days 2019"](https://www.youtube.com/watch?v=o-6EMTjzvns)

# License

Showdown is distributed under the Unreal Engine EULA. See [LICENSE](./LICENSE)

https://www.unrealengine.com/en-US/eula/unreal

# Contribution

See the [CONTRIBUTING](./CONTRIBUTING.md) file for how to help out.
