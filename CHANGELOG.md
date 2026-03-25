# Changelog
All notable changes to this project will be documented in this file.

## 12/22/2025
### Update
Updated project to use OpenXR backend.
Note: Changing MSAA level at runtime is not supported with OpenXR backend. It has been disabled in the sample project.

## 11/26/2025
### Update
Updated project to UE5.6 + Meta XR SDK v81.

### Fixes
We've identified an issue when enabling foveated rendering in combination with MSAA 0x, which produce a visual glitch. As a workaround, we've disabled the possibility to activate these settings at the same time.
