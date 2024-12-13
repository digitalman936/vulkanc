#pragma once

#include "core/defines.h"

struct PlatformState
{
	void* internal_state;
} typedef PlatformState;

b8 platform_startup(PlatformState* platform_state, const char* application_name, i32 x, i32 y, i32 width, i32 height);

void platform_shutdown(const PlatformState* platform_state);

b8 platform_pump_messages();
