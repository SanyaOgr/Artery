#include "Mouse.h"
#include "Input/Input.h"

namespace engine {

    bool Mouse::IsButtonPressed(Button button)
    {
        return Input::IsMouseButtonPressed(button);
    }

    Vector2i Mouse::GetPosition()
    {
        return Input::GetMouseAbsolutePosition();
    };

}