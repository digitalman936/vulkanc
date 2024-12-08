#include <platform/platform.h>

#include "defines.h"

int main()
{
	PlatformState state;

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
