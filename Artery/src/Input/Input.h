#pragma once
#include "Input/Keyboard.h"
#include "Input/Mouse.h"
#include "Input/InputImpl.h"
#include "Utils/Vector2.h"

namespace engine {

	class Mouse;
	class Keyboard;

	class Input
	{
	public:
		static bool IsKeyPressed(Keyboard::Key key);

		static bool IsMouseButtonPressed(Mouse::Button button);

		static Vector2i GetMouseAbsolutePosition();

	private:
		static InputImpl* m_impl;

	};

}