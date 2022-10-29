#include "WindowImpl.h"
#include <iostream>

#if defined(_WIN32)
	#include "Platform/Win32/WindowImplWin32.h";
	using WindowImplPlatform = engine::WindowImplWin32;
#endif

namespace engine {

	WindowImpl* WindowImpl::Create(const std::string& title, unsigned int width, unsigned int height)
	{
		return new WindowImplPlatform(title, width, height);
	}

	WindowImpl::WindowImpl()
	{
	}

	WindowImpl::~WindowImpl() = default;

}