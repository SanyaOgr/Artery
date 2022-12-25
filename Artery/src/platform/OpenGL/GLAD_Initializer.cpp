#include "artpch.h"
#include "GLAD_Initializer.h"

#if defined(ARTERY_SYSTEM_WINDOWS)

	#include "platform/windows/Windows_GLAD_Initializer.h"
	namespace art {
		using GLAD_InitializerType = Windows_GLAD_Initializer;
	}

#endif

namespace art {

	ScopePtr<GLAD_Initializer> GLAD_Initializer::s_platformImpl;
	bool GLAD_Initializer::s_initialized = false;

	ScopePtr<GLAD_Initializer>& GLAD_Initializer::Get()
	{
		if (!s_initialized)
		{
			s_platformImpl = create();
		}
		return s_platformImpl;
	}

	ScopePtr<GLAD_Initializer> GLAD_Initializer::create()
	{
		return std::make_unique<GLAD_InitializerType>();
	}

}