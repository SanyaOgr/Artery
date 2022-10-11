#pragma once
#include <cstdint>

namespace util {

	enum MouseButton
	{
		Left,
		Cancel,
		Right,
		Middle,
		None
	};

	struct MouseEventArgs
	{
		MouseEventArgs(int x = 0, int y = 0, MouseButton button = None, uint16_t param = 0)
			: button(button), xPos(x), yPos(y), param(param)
		{}

		int xPos;
		int yPos;
		MouseButton button;
		uint16_t param;
	};

	struct KeyEventArgs
	{
		KeyEventArgs(int key, uint16_t param = 0)
			: keycode(key), param(param)
		{}

		int keycode;
		uint16_t param;
	};

	struct WindowResizeEventArgs
	{
		WindowResizeEventArgs(int width, int height)
			: width(width), height(height)
		{}

		int width;
		int height;
	};



}