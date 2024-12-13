#include "debug_messenger.h"

VkBool32 debug_callback(VkDebugUtilsMessageSeverityFlagBitsEXT message_severity,
						VkDebugUtilsMessageTypeFlagsEXT message_type,
						const VkDebugUtilsMessengerCallbackDataEXT* callback_data, void* user_data)
{
	printf("Validation Layer: %s\n", callback_data->pMessage);

	return VK_FALSE;
}

b8 create_debug_messenger(Context* context)
{
	VkDebugUtilsMessengerCreateInfoEXT create_info;
	create_info.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
	create_info.pNext = NULL;
	create_info.flags = 0;
	create_info.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
								  VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT |
								  VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
								  VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
	create_info.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
							  VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
							  VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
	create_info.pfnUserCallback = &debug_callback;
	create_info.pUserData = NULL;

	if (_create_debug_messenger(context->instance, &create_info, NULL, &context->debug_messenger) != VK_SUCCESS)
	{
		printf("Failed to create vulkan debug messenger.\n");
		return FALSE;
	}

	return TRUE;
}

void destroy_debug_messenger(const Context* context)
{
	_destroy_debug_messenger(context->instance, context->debug_messenger, NULL);
}

VkResult _create_debug_messenger(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* create_info,
								 const VkAllocationCallbacks* allocator, VkDebugUtilsMessengerEXT* debug_messenger)
{
	PFN_vkCreateDebugUtilsMessengerEXT function = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(
		instance, "vkCreateDebugUtilsMessengerEXT");

	if (function != NULL)
	{
		return function(instance, create_info, allocator, debug_messenger);
	}

	return VK_ERROR_EXTENSION_NOT_PRESENT;
}

void _destroy_debug_messenger(VkInstance instance, VkDebugUtilsMessengerEXT debug_messenger,
							  const VkAllocationCallbacks* allocator)
{
	PFN_vkDestroyDebugUtilsMessengerEXT function = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(
		instance, "vkDestroyDebugUtilsMessengerEXT");

	if (function != NULL)
	{
		function(instance, debug_messenger, allocator);
	}
}
