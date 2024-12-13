#include "extensions.h"
#include <vulkan/vulkan_core.h>

const char* const* get_required_extensions(u32* count)
{
	// TODO: implement platform specific extensions for linux
	#if defined(VC_PLATFORM_WINDOWS)
	static const char* const* extension_names[] = {"VK_KHR_surface",
												   "VK_KHR_win32_surface",
												   VK_EXT_DEBUG_UTILS_EXTENSION_NAME};
	*count = sizeof(extension_names) / sizeof(extension_names[0]);
	return extension_names;
	#else
	*count = 0;
	return NULL;
	#endif
}
