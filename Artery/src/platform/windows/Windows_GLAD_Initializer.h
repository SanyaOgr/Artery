#pragma once

#include "platform/OpenGL/GLAD_Initializer.h"

namespace art {

	class Windows_GLAD_Initializer : public GLAD_Initializer
	{
	public:
		void Init() override;
	};

}