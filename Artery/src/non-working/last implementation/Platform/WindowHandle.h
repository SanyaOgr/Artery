#pragma once

#if defined(_WIN32)
	struct HWND__;
#endif

namespace engine {

#if defined(_WIN32)
	using WindowHandle = HWND__*;
#endif

}