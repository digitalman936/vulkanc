#include <stdlib.h>

#include "platform/platform.h"
#include "renderer/renderer.h"

int main()
{
	PlatformState state;
	Context context;

	create_renderer(&context);

	if (platform_startup(&state, "Vulkanc", 400, 400, 600, 400))
	{
		while (TRUE)
		{
			if (!platform_pump_messages())
			{
				break;
			}
		}
	}

	destroy_renderer(&context);
	platform_shutdown(&state);

	return 0;
}
