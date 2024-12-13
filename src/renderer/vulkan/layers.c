#include "layers.h"

#include <stdio.h>

const char* const* get_required_layers(u32* count)
{
	#if defined(VC_VULKAN_VALIDATION_LAYERS_ENABLED)
	static const char* layer_names[] = {"VK_LAYER_KHRONOS_validation"};
	*count = sizeof(layer_names) / sizeof(layer_names[0]);
	return layer_names;
	#else
	*count = 0;
	return NULL;
	#endif
}
