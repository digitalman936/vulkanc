cmake_minimum_required(VERSION 3.20)
project(vulkanc LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

if (MSVC)
    set(COMPILER_NAME "msvc")
    message("Your Compiler: ${CMAKE_C_COMPILER_ID}")
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
elseif (${CMAKE_C_COMPILER_ID} MATCHES "Clang")
    set(COMPILER_NAME "clang")
elseif (${CMAKE_C_COMPILER_ID} MATCHES "GNU")
    set(COMPILER_NAME "gcc")
else ()
    set(COMPILER_NAME "unsupported_compiler")
    message(WARNING "You are using an untested compiler: ${CMAKE_C_COMPILER_ID}. "
            "This project is tested with MSVC, Clang, and GCC.")
endif ()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(BUILD_MODE "debug")
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(BUILD_MODE "release")
else()
    set(BUILD_MODE "")
endif ()

set(CMAKE_BIN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build/bin/${COMPILER_NAME}/${BUILD_MODE}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BIN_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BIN_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BIN_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BIN_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BIN_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BIN_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BIN_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BIN_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BIN_DIR})

find_package(Vulkan REQUIRED)

add_subdirectory(src)