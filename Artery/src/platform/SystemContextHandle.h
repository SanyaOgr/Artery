#pragma once

#include "core/Config.h"

#if defined(ARTERY_SYSTEM_WINDOWS)

	struct HGLRC__;
	namespace art {
		using SystemGLContextHandle = HGLRC__*;
	}

	struct HDC__;
	namespace art {
		using SystemDeviceContextHandle = HDC__*;
	}

#endif