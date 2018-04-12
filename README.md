# DX12

This is the Direct3D 12 repository for the application as described in "Comparing Direct3D 12 and Vulkan on Performance and Programmability".
The relevant code is located in the DX12Projects/OrganizedDirectX12 folder.

Associated repos are:
* https://github.com/dpw901e17/vulkan-application
* https://github.com/dpw901e17/data

## Requirements

For running the program:
* 64-bit version of Windows 10
* Visual Studio 15 or later
* Graphics card compatible with Direct3D12

The include path for windows header is set to use version 10.0.16299.0 and will most likely have to be updated.

For running the tests, we additionally require Open Hardware Monitor v. 0.7.1 beta to be installed at "%PROGAMFILES(x84)%\OpenHardwareMonitor".
It can be installed from http://openhardwaremonitor.org/.

## Run the tests
Tests are executed in release mode building for x64 processors.

Tests can be executed with either a cube-model or a skull-model. You can define the one to use through the macro in file "stdafx.h" at line 139, which should be set to TEST_USE_CUBE or TEST_USE_SKULL. Note that compiling with skull takes much longer than with cube.

The repository is set up for running two types of tests, which are executed through bat-scripts run in the same directory as the application executable. Folders containing generated data are named with a timestamp.
* "ThreadDataCollector.bat" is used for tests, where the number of threads for command submission is increased.
* "testrig.bat" is used for tests, where the number of objects to render is increased. When running the test, any of the 3 initials (b/c/m) can be used, as it is only used for labeling the files containing Open Hardware Monitor data. 


## Setting up Direct3D 12.
Errors that may occour when Direct3D 12 is not properly set up:

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

## Acknowledgements
https://www.braynzarsoft.net/ was used as a starting off point, when creating this repository. Thus there may be some similarities in program structure.

The skull model used for high-polygon testing was downloaded from https://free3d.com/3d-model/skull-human-anatomy-82445.html.
