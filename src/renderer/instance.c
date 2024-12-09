#include "instance.h"

#include <stdio.h>

b8 renderer_create_vulkan_instance(VulkanContext *context)
{
	VkApplicationInfo application_info = {};
	application_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	application_info.pNext = NULL;
	application_info.pApplicationName = "VulkanC Application";
	application_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	application_info.pEngineName = "VulkanC Engine";
	application_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	application_info.apiVersion = VK_API_VERSION_1_3;

	VkInstanceCreateInfo create_info = {};
	create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	create_info.pNext = NULL;
	create_info.pApplicationInfo = &application_info;
	create_info.enabledLayerCount = 0;
	create_info.ppEnabledLayerNames = NULL;
	create_info.enabledExtensionCount = 0;
	create_info.ppEnabledExtensionNames = NULL;

	VkInstance instance;

	if (vkCreateInstance(&create_info, NULL, &instance) != VK_SUCCESS)
	{
		printf("Failed to create Vulkan instance.");
		return FALSE;
	}

	context->instance = instance;

	return TRUE;
}

void renderer_destroy_vulkan_instance(const VulkanContext *context)
{
	vkDestroyInstance(context->instance, NULL);
}
