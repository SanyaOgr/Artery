#pragma once
#include <string>
#include "WindowImpl.h"

namespace engine {

	class Window
	{
	public:
		Window(const std::string& title, unsigned int width, unsigned int height);

		WindowHandle GetHandle() const;

		void Update();

		bool IsOpen() const;

		void Close();

		void SetTitle(const std::string& title);

	private:
		WindowImpl* m_impl;

	};

}