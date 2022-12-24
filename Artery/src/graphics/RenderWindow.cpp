#include "RenderWindow.h"

namespace art {

	RenderWindow::RenderWindow(const WindowSettings& settings)
		: Window(settings)
	{
		m_graphicsContext = new GraphicsContext(*this);
		m_graphicsContext->SetCurrentDeviceContext(GetSystemDeviceContextHandle());

	}

	RenderWindow::~RenderWindow()
	{
		delete m_graphicsContext;
	}

	void RenderWindow::SetActive(bool active)
	{
		m_graphicsContext->SetActive();
	}

}

