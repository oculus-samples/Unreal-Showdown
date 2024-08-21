:: Copyright (c) Meta Platforms, Inc. and affiliates. All rights reserved.
:: Generate PSO Cache

:: Usage
:: From https://dev.epicgames.com/documentation/en-us/unreal-engine/creating-bundled-pso-caches-for-android-in-unreal-engine?application_version=5.4
:: - Pass UE_ROOT (path) as the first argument, use the same engine version that was used to build the app
:: - Deploy the application, plug in the device so that it's listed on when calling `adb devices`
:: - Run this script, wait for the application to launch automatically
:: - After collection the PSOs, close the application and resume the script execution
:: - Ensure that Showdown_SF_VULKAN_ES31_ANDROID.spc is generated, rebuild the app
echo off
SETLOCAL
set UE_ROOT=%1
IF "%UE_ROOT%"==""  (
    echo UE_ROOT not defined, usage "./GeneratePSOCache.bat <UE_ROOT>"
    exit
)
set WORKING_DIRECTORY=%cd%
set PROJ_NAME=Showdown
set PROJ_DIR=%WORKING_DIRECTORY%
set CACHE_DIR=%WORKING_DIRECTORY%\PSOCache

:: Enable PSO logging on the device and launch the app
adb shell setprop debug.ue.commandline "-logPSO"
adb shell monkey -p com.samples.ShowdownQuest -c android.intent.category.LAUNCHER 1
pause

:: Reset command line launch args
adb shell setprop debug.ue.commandline \" \"

:: Clear current cache files
@rd /S /Q %CACHE_DIR%

:: Copy PipelineCaches from project
md %CACHE_DIR%
copy %PROJ_DIR%\Saved\Cooked\Android_ASTC\%PROJ_NAME%\Metadata\PipelineCaches %CACHE_DIR%

:: Copy rec.upipelinecache from device
adb pull /sdcard/Android/Data/com.samples.ShowdownQuest/files/UnrealGame/Showdown/Showdown/Saved/CollectedPSOs
copy /Y CollectedPSOs %CACHE_DIR%
@rd  /S /Q CollectedPSOs

:: Expand PSO cache to generate spc file
for %%f in (%CACHE_DIR%%\*.upipelinecache) do (
    call set "UPIPELINE_CACHE=%%UPIPELINE_CACHE%% %%f"
)

for %%f in (%CACHE_DIR%%\*.shk) do (
    call set "SHK_CACHE=%%SHK_CACHE%% %%f"
)

set SPC_FILE=%CACHE_DIR%\%PROJ_NAME%_SF_VULKAN_ES31_ANDROID.spc

"%UE_ROOT%\Engine\Binaries\Win64\UnrealEditor-Cmd.exe" -run=ShaderPipelineCacheTools Expand %UPIPELINE_CACHE% %SHK_CACHE% %SPC_FILE%

:: Copy output to Project
md %PROJ_DIR%\Build\Android\PipelineCaches
copy %SPC_FILE% %PROJ_DIR%\Build\Android\PipelineCaches
md %PROJ_DIR%\Build\Android_ASTC\PipelineCaches
copy %SPC_FILE% %PROJ_DIR%\Build\Android_ASTC\PipelineCaches

pause