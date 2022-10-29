#pragma once
#include "Input/Keyboard.h"
#include "Input/Mouse.h"
#include "Utils/Vector2.h"

namespace engine {

	class InputImpl
	{
	public:
		//InputImpl() = default;

		static InputImpl* Create();

		virtual bool IsKeyPressed(Keyboard::Key key) = 0;
		virtual bool IsMouseButtonPressed(Mouse::Button button) = 0;
		virtual Vector2i GetMouseAbsolutePosition() = 0;
	};

}