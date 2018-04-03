# DX12

This is the DX12 repository for the AAU 9th semester pre-specialization project for the group dpw901e17.
This is one part of the repositories for this project.
The others are:
* scene-window-system: https://github.com/dpw901e17/scene-window-system.git *included with this project
* Vulkan: https://github.com/dpw901e17/vulkan-application.git

The relevant code for this project is located in the DX12Projects/OrganizedDirectX12 folder.

scene-window-system is a subsystem on its own repository and contains objects which are reused between the two main repositories.

Setting up Direct3D12.

Errors that may occour when Direct3D12 is not properly set up:

	Error MSB8036 The Windows SDK version 10.0.16299.0 was not found. Install the required version of Windows SDK or change the SDK version in the project property pages or by right-clicking the solution and selecting "Retarget solution".	OrganizedDirectX12	C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\VC\VCTargets\Platforms\x64\PlatformToolsets\v141\Toolset.targets	36	
	Direct3D12 files which cannot be included due to linker errors

Firstly make sure that the newest Windows SDK version is installed, if the error still persist do the following steps:

1. Open PropertyPages for the OrganizedDirectX12 project.

2. Go to "VC++ Directories"

3. "Include directories" should include:
C:\Program Files (x86)\Windows Kits\10\Include\[Your-Windows-10-SDK-version-number]\shared
C:\Program Files (x86)\Windows Kits\10\Include\[Your-Windows-10-SDK-version-number]\um

4. "Library Directories" should include:
C:\Program Files (x86)\Windows Kits\10\Lib\[Your-Windows-10-SDK-version-number]\um\x64

5. Go to "Linker", under that, Go to "Input".

6. Additional Dependencies should include:
d3d12.lib
dxgi.lib
d3dcompiler.lib

7. Go to "Configuration Properties"

8. "Windows SDK Version" should be the same version you are using.

Please note that setting the application to compile the Skull model takes significantly more time than the Cube model.
To render with Cubes or Skulls go to line 139 in stdafx.h and either write

TEST_USE_SKULL
or
TEST_USE_CUBE

## Acknowledgements
https://www.braynzarsoft.net/ was used as a starting off point, when creating this repository. Thus there may be some similariites in program structure.
