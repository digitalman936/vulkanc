cmake_minimum_required(VERSION 3.20)
project(src LANGUAGES C)

set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
file(GLOB_RECURSE CPP_SOURCE "${SOURCE_DIR}/*.c")
file(GLOB_RECURSE HPP_SOURCE "${SOURCE_DIR}/*.h")

add_executable(${PROJECT_NAME} ${CPP_SOURCE} ${HPP_SOURCE})
target_include_directories(${PROJECT_NAME} PUBLIC ${SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE Vulkan::Vulkan)

target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:VC_DEBUG_BUILD>"
        "$<$<CONFIG:Release>:VC_RELEASE_BUILD>"
)