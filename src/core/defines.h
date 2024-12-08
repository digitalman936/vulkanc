#pragma once

// Ensure operating system architecture supports 64-bit
#if defined(_WIN64) || defined(__x86_64__) || defined(__ppc64__) || defined(__LP64__) || defined(_M_X64) ||            \
    defined(__aarch64__) || defined(_M_ARM64)
    #define VC_PLATFORM_ARCHITECTURE_64_BIT
#else
    #error "A 64-bit operating system is required to build."
#endif

// Check for Windows operating system
#if defined(_WIN64)
    #define VC_PLATFORM_WINDOWS
// Check for Android operating system
#elif defined(__ANDROID__)
    #define VC_PLATFORM_ANDROID
// Check for Apple operating systems (macOS, iOS, tvOS, watchOS, etc.)
#elif defined(__APPLE__) && defined(__MACH__)
    #if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
	#define VC_PLATFORM_IOS
    #else
	#define VC_PLATFORM_MACOS
    #endif
// Check for Linux based operating systems (Debian, Arch, RHL, etc.)
#elif defined(__linux__)
    #define VC_PLATFORM_LINUX
// Check for Unix based operating systems (FreeBSD, OpenBSD, etc.)
#elif defined(__unix__)
    #define VC_PLATFORM_UNIX
// Playstation consoles
#elif defined(__ORBIS__)
    #define VC_PLATFORM_PLAYSTATION
// Nintendo consoles
#elif defined(__NX__)
    #define VC_PLATFORM_NINTENDO
// Xbox consoles
#elif defined(_DURANGO) || defined(_XBOX_ONE) || defined(_GAMING_XBOX)
    #define VC_PLATFORM_XBOX
// Unsupported operating systems
#else
    #error "A supported operating system is required to build."
#endif

// Check for supported compilers
#if defined(_MSC_VER)
	#define VC_COMPILER_MSVC
#elif defined(__clang__)
	#define VC_COMPILER_CLANG
#elif defined(__GNUC__) || defined(__GNUG__)
	#define VC_COMPILER_GCC
#else
    #error "A supported compiler such as MSVC, Clang, or GCC is required to build."
#endif

// Ensure proper debug breaks
#if defined(VC_COMPILER_MSVC)
    #define VC_DEBUG_BREAK __debugbreak()
#elif defined(VC_COMPILER_GCC) || defined(VC_COMPILER_CLANG)
    #define VC_DEBUG_BREAK __builtin_trap()
#endif

// Preset debug info
#if defined(VC_DEBUG_BUILD)
    #define VC_ENABLE_ALL_ASSERTIONS
    #define VC_ENABLE_ALL_LOGGING
#endif
#if defined(VC_RELEASE_BUILD)
    #define VC_ENABLE_MINIMAL_ASSERTIONS
    #define VC_ENABLE_MINIMAL_LOGGING
#endif

// Vulkan validation
#if defined(VC_DEBUG_BUILD)
    #define VC_VULKAN_VALIDATION_LAYERS_ENABLED
#endif

// Compiler-Specific assertions
#if defined(VC_COMPILER_CLANG) || defined(VC_COMPILER_GCC)
    #define VC_STATIC_ASSERT _Static_assert
#else
    #define VC_STATIC_ASSERT static_assert
#endif

// Unsigned int primitives
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// Signed int primitives
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

// Floating point primitives
typedef float f32;
typedef double f64;

// Boolean primitives
typedef int b32;
typedef char b8;

#define TRUE 1
#define FALSE 0

// Compiler specific assertions
#if defined(VC_COMPILER_CLANG) || defined(VC_COMPILER_GCC)
	#define STATIC_ASSERT _Static_assert
#else
	#define STATIC_ASSERT static_assert
#endif

// Ensure all types are of the correct size
STATIC_ASSERT(sizeof(u8) == 1, "Expected u8 to be 1 byte.");
STATIC_ASSERT(sizeof(u16) == 2, "Expected u16 to be 2 bytes.");
STATIC_ASSERT(sizeof(u32) == 4, "Expected u32 to be 4 bytes.");
STATIC_ASSERT(sizeof(u64) == 8, "Expected u64 to be 8 bytes.");

STATIC_ASSERT(sizeof(i8) == 1, "Expected i8 to be 1 byte.");
STATIC_ASSERT(sizeof(i16) == 2, "Expected i16 to be 2 bytes.");
STATIC_ASSERT(sizeof(i32) == 4, "Expected i32 to be 4 bytes.");
STATIC_ASSERT(sizeof(i64) == 8, "Expected i64 to be 8 bytes.");

STATIC_ASSERT(sizeof(f32) == 4, "Expected f32 to be 4 bytes.");
STATIC_ASSERT(sizeof(f64) == 8, "Expected f64 to be 8 bytes.");
