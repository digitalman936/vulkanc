#include "renderer.h"

#include "renderer/vulkan/instance.h"
#include "vulkan/debug_messenger.h"

b8 create_renderer(Context* context)
{
	create_instance(context);
	create_debug_messenger(context);

	return TRUE;
}

void destroy_renderer(const Context* context)
{
	destroy_debug_messenger(context);
	destroy_instance(context);
}
