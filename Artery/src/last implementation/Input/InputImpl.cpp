#include "Input/InputImpl.h"

#if defined(_WIN32)
	#include "Platform/Win32/InputImplWin32.h"
	using InputImplPlatform = engine::InputImplWin32;
#endif

namespace engine {

	InputImpl* InputImpl::Create()
	{
		return new InputImplPlatform;
	}

}