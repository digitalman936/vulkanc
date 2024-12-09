#pragma once

#include "context.inl"
#include "core/defines.h"

b8 renderer_startup(VulkanContext *context);
void renderer_shutdown(const VulkanContext *context);