#include "instance.h"
#include <stdio.h>

#include "debug_messenger.h"
#include "extensions.h"
#include "layers.h"

b8 create_instance(Context* context)
{
	VkApplicationInfo application_info = {};
	application_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	application_info.pNext = NULL;
	application_info.pApplicationName = "VulkanC Application";
	application_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	application_info.pEngineName = "VulkanC Engine";
	application_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	application_info.apiVersion = VK_API_VERSION_1_3;

	u32 extension_count = 0;
	const char* const* extension_names = get_required_extensions(&extension_count);

	u32 layer_count = 0;
	const char* const* layer_names = get_required_layers(&layer_count);

	VkInstanceCreateInfo create_info = {};
	create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	create_info.pNext = NULL;
	create_info.pApplicationInfo = &application_info;
	create_info.enabledLayerCount = layer_count;
	create_info.ppEnabledLayerNames = layer_names;
	create_info.enabledExtensionCount = extension_count;
	create_info.ppEnabledExtensionNames = extension_names;

	VkInstance instance = {};

	#if defined(VC_VULKAN_VALIDATION_LAYERS_ENABLED)
	VkDebugUtilsMessengerCreateInfoEXT debug_messenger_create_info = {};
	debug_messenger_create_info.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
	debug_messenger_create_info.pNext = NULL;
	debug_messenger_create_info.flags = 0;
	debug_messenger_create_info.messageSeverity = //VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
								  VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT |
								  VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
								  VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
	debug_messenger_create_info.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
							  VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
							  VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
	debug_messenger_create_info.pfnUserCallback = &debug_callback;
	debug_messenger_create_info.pUserData = NULL;

	create_info.pNext = &debug_messenger_create_info;
	#endif

	for (u32 i = 0; i < extension_count; i++)
	{
		printf("Vulkan Extension: %s\n", extension_names[i]);
	}

	for (u32 i = 0; i < layer_count; i++)
	{
		printf("Vulkan Layer: %s\n", layer_names[i]);
	}

	if (vkCreateInstance(&create_info, NULL, &instance) != VK_SUCCESS)
	{
		printf("Failed to create Vulkan instance.");
		return FALSE;
	}

	context->instance = instance;

	return TRUE;
}

void destroy_instance(const Context* context)
{
	vkDestroyInstance(context->instance, NULL);
}
