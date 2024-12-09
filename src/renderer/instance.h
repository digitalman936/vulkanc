#pragma once

#include "context.inl"
#include "renderer.h"

b8 renderer_create_vulkan_instance(VulkanContext *context);
void renderer_destroy_vulkan_instance(const VulkanContext *context);
