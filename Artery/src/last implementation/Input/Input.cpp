#include "Input/Input.h"

namespace engine {

	InputImpl* Input::m_impl = InputImpl::Create();

	bool Input::IsKeyPressed(Keyboard::Key key)
	{
		return m_impl->IsKeyPressed(key);
	}

	bool Input::IsMouseButtonPressed(Mouse::Button button)
	{
		return m_impl->IsMouseButtonPressed(button);
	}

	Vector2i Input::GetMouseAbsolutePosition()
	{
		return m_impl->GetMouseAbsolutePosition();
	}

}