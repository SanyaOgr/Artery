#pragma once

namespace art {

#ifdef _WIN32
	#include <Windows.h>
	using PlatformWindowHandle = HWND;
#endif

}