# Vulkan C

My personal C with vulkan project which follows the [Vulkan Tutorial](https://vulkan-tutorial.com/). I am a 16 year old who is intermedietely experienced in C++, but I decided to use C for more simplicity and less bloated code. 
This project has no dependencies except for the [VulkanSDK](https://vulkan.lunarg.com/sdk/home) by LunarG. 

## Requirements

* A compiler with C11 support.
* CMake and Ninja-Build.
* The VulkanSDK.
* An x64 operating system. 

## Build Instructions

Clone the repository.
```
git clone https://github.com/digitalman936/vulkanc.git && cd vulkanc
```

Use CMake to generate Ninja-Build with your choice of compiler and build configuration. For example, with clang:
```
cmake --preset clang-debug
cmake --preset clang-release
```

Compile and link using the chosen CMake preset: 
```
cmake --build --preset clang-debug-build
cmake --build --preset clang-release-build
```

You can use the command `cmake --list-presets` in the root directory to get a list of all of the currently available presets for the project. 

> **Note:** The current only supported generator for this project is Ninja. MSBuild for Visual Studio 2022, XCode, and Make will all be supported in the future. 
