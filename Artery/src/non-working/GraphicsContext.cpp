#include "GraphicsContext.h"

namespace art::graphics {

	GraphicsContext::~GraphicsContext()
	{
		delete m_platformImpl;
	}

}