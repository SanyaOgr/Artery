#include "GLAD_Initializer.h"

#include "core/Config.h"

#if defined(ARTERY_SYSTEM_WINDOWS)

	#include "platform/windows/Windows_GLAD_Initializer.h"
	namespace art {
		using GLAD_InitializerType = Windows_GLAD_Initializer;
	}

#endif

namespace art {

	std::unique_ptr<GLAD_Initializer> GLAD_Initializer::m_platformImpl;
	bool GLAD_Initializer::initialized = false;

	std::unique_ptr<GLAD_Initializer>& GLAD_Initializer::Get()
	{
		if (!initialized)
		{
			m_platformImpl = create();
		}
		return m_platformImpl;
	}

	std::unique_ptr<GLAD_Initializer> GLAD_Initializer::create()
	{
		return std::make_unique<GLAD_InitializerType>();
	}

}