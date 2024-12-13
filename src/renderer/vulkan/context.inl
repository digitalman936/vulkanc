#pragma once

#include <vulkan/vulkan.h>

struct Context
{
	VkInstance instance;
	VkDebugUtilsMessengerEXT debug_messenger;
} typedef Context;
