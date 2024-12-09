#include "renderer.h"

#include "instance.h"

b8 renderer_startup(VulkanContext *context)
{
	renderer_create_vulkan_instance(context);

	return TRUE;
}

void renderer_shutdown(const VulkanContext *context)
{
	renderer_destroy_vulkan_instance(context);
}
