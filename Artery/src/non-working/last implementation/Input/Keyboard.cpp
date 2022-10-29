#include "Keyboard.h"
#include "Input/Input.h"

namespace engine {

    bool Keyboard::IsKeyPressed(Key key)
    {
        return Input::IsKeyPressed(key);
    }

}