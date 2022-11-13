#pragma once
#include "Config.h"

#if defined(ARTERY_SYSTEM_WINDOWS)

	struct HWND__;
	namespace art {
		using SystemWindowHandle = HWND__*;
	}

#endif