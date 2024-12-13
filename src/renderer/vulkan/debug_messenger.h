#pragma once

#include <stdio.h>
#include <vulkan/vulkan.h>
#include "context.inl"
#include "core/defines.h"

VKAPI_ATTR VkBool32 VKAPI_CALL debug_callback(VkDebugUtilsMessageSeverityFlagBitsEXT message_severity,
													 VkDebugUtilsMessageTypeFlagsEXT message_type,
													 const VkDebugUtilsMessengerCallbackDataEXT* callback_data,
													 void* user_data);

b8 create_debug_messenger(Context* context);

void destroy_debug_messenger(const Context* context);

static VkResult _create_debug_messenger(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* create_info,
										const VkAllocationCallbacks* allocator,
										VkDebugUtilsMessengerEXT* debug_messenger);

static void _destroy_debug_messenger(VkInstance instance, VkDebugUtilsMessengerEXT debug_messenger,
									 const VkAllocationCallbacks* allocator);
