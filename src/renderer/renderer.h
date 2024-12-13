#pragma once

#include "core/defines.h"
#include "vulkan/context.inl"

b8 create_renderer(Context* context);

void destroy_renderer(const Context* context);
