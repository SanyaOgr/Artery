#pragma once

#ifdef _WIN32
	struct HWND__;
	namespace art {
		using PlatformWindowHandle = HWND__*;
	}
#endif