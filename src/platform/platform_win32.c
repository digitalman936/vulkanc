#include "platform.h"

#ifdef VC_PLATFORM_WINDOWS

#include <windows.h>

struct InternalState
{
	HINSTANCE instance_handle;
	HWND window_handle;
} typedef InternalState;

LRESULT CALLBACK win32_process_message(HWND hwnd, u32 msg, WPARAM w_param, LPARAM l_param);

b8 platform_startup(PlatformState* platform_state, const char* application_name, const i32 x, const i32 y,
					const i32 width, const i32 height)
{
	platform_state->internal_state = malloc(sizeof(InternalState));
	InternalState* state = platform_state->internal_state;

	state->instance_handle = GetModuleHandleA(0);

	WNDCLASS window_class = {};
	window_class.style = CS_DBLCLKS;
	window_class.lpfnWndProc = win32_process_message;
	window_class.cbClsExtra = 0;
	window_class.cbWndExtra = 0;
	window_class.hInstance = state->instance_handle;
	window_class.hIcon = LoadIcon(state->instance_handle, IDI_APPLICATION);
	window_class.hCursor = LoadCursor(NULL, IDC_ARROW);
	window_class.hbrBackground = NULL;
	window_class.lpszMenuName = NULL;
	window_class.lpszClassName = "VulkanC Window Class";

	if (!RegisterClassA(&window_class))
	{
		MessageBoxA(0, "Failed to register window.", "Error", MB_ICONEXCLAMATION | MB_OK);
		return FALSE;
	}

	const u32 client_x = x;
	const u32 client_y = y;
	const u32 client_width = width;
	const u32 client_height = height;
	u32 window_x = client_x;
	u32 window_y = client_y;
	u32 window_width = client_width;
	u32 window_height = client_height;

	u32 window_style = WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION;
	const u32 window_ex_style = WS_EX_APPWINDOW;
	window_style |= WS_MAXIMIZEBOX;
	window_style |= WS_MINIMIZEBOX;
	window_style |= WS_THICKFRAME;

	RECT border_rect = {0, 0, 0, 0};
	AdjustWindowRectEx(&border_rect, window_style, 0, window_ex_style);

	window_x += border_rect.left;
	window_y += border_rect.top;

	window_width += border_rect.right - border_rect.left;
	window_height += border_rect.bottom - border_rect.top;

	const HWND handle = CreateWindowExA(window_ex_style, "Vulkanc Window Class", application_name, window_style,
										window_x, window_y, window_width, window_height, 0, 0, state->instance_handle,
										0);

	if (!handle)
	{
		MessageBoxA(NULL, "Failed to create window", "Error", MB_ICONEXCLAMATION | MB_OK);

		return FALSE;
	}

	state->window_handle = handle;

	const b32 should_activate = TRUE;
	const i32 show_window_command_flags = should_activate ? SW_SHOW : SW_SHOWNOACTIVATE;
	ShowWindow(state->window_handle, show_window_command_flags);

	return TRUE;
}

void platform_shutdown(const PlatformState* platform_state)
{
	InternalState* state = platform_state->internal_state;

	if (state->instance_handle)
	{
		DestroyWindow(state->window_handle);
		state->window_handle = NULL;
	}
}

b8 platform_pump_messages()
{
	MSG message;

	while (PeekMessageA(&message, NULL, 0, 0, PM_REMOVE))
	{
		if (message.message == WM_QUIT)
		{
			return FALSE;
		}

		TranslateMessage(&message);
		DispatchMessageA(&message);

	}

	return TRUE;
}

LRESULT CALLBACK win32_process_message(const HWND hwnd, const u32 msg, const WPARAM w_param, const LPARAM l_param)
{
	switch (msg)
	{
		case WM_CLOSE:
			DestroyWindow(hwnd);
			return 0;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}

	return DefWindowProcA(hwnd, msg, w_param, l_param);
}

#endif
