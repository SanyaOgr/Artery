#pragma once

#include <string>

#include "PlatformTypes.h"

namespace art {

	class WindowImpl
	{
	public:
		static WindowImpl* Create(int width, int height, const std::string& title);

		virtual void SetVisible(bool visible) = 0;

		virtual void ProcessEvents() = 0;

	protected:
		WindowImpl(int width, int height, const std::string& title);

		virtual PlatformWindowHandle getPlatformHandle() = 0;

	protected:
		std::string m_title;
		int m_width;
		int m_height;
	};

}