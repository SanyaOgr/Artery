#pragma once
#include "Utils/Vector2.h"

namespace engine {

	class Mouse
	{
	public:
        enum Button
        {
            Left,      
            Right,     
            Middle,    
            XButton1,  
            XButton2,  

            ButtonCount
        };

        static bool IsButtonPressed(Button button);

        static Vector2i GetPosition();

	};

}