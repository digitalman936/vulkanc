#include "defines.h"
#include "platform/platform.h"
#include "renderer/renderer.h"

int main()
{
	PlatformState state;
	VulkanContext context;

	renderer_startup(&context);
	renderer_shutdown(&context);

	if (platform_startup(&state, "Vulkanc", 400, 400, 600, 400))
	{
		while (TRUE)
		{
			platform_pump_messages();
		}
	}

	platform_shutdown(&state);

	return 0;
}
