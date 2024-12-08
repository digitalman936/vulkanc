# Vulkan C

My personal C & Vulkan project which follows the [Vulkan Tutorial](https://vulkan-tutorial.com/). For context, I am a
16-year-old rookie-programmer who has used C++ in the past for small OpenGL projects, but I decided to use C for more
simplicity and less bloated code, and learn Vulkan for more low-level control over the graphics hardware and
multi-threading capability. This project has no dependencies except for
the [VulkanSDK](https://vulkan.lunarg.com/sdk/home) by LunarG.

I would like to credit [Travis Vroman](https://www.youtube.com/c/travisvroman) and
his [Kohi Game Engine Series](https://www.youtube.com/watch?v=dHPuU-DJoBM&list=PLv8Ddw9K0JPg1BEO-RS-0MYs423cvLVtj) for
giving me the inspiration to start this project. Going from C++ to C was certainly a big change, but so far I wouldn't
go back!

## Requirements

* A compiler with C v11 support.
* CMake v3.19 or higher and Ninja-Build.
* The VulkanSDK v1.2 or higher.
* A x64-bit operating system with Vulkan v1.2 or higher support. (Most hardware past 2018)

## Build Instructions

Clone the repository.

```
git clone https://github.com/digitalman936/vulkanc.git && cd vulkanc
```

Use CMake to generate Ninja-Build with your choice of compiler and build configuration.

To list the available CMake presets to generate:

```
cmake --list-presets
```

For example, to use clang in debug mode:

```
cmake --preset clang-debug
```

Or, to use clang in release mode:

```
cmake --preset clang-release
```

To compile and link the generated CMake presets:

```
cmake --build --preset clang-debug-build && cmake --build --preset clang-release-build
```

> **Note:** The current only supported generator for this project is Ninja. MSBuild for Visual Studio 2022, XCode, and
> Make will all be supported in the future. 
