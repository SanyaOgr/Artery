#pragma once

#include <glad/glad.h>
#include "GraphicsContext.h"

namespace art {

	class VertexBuffer; // temporary

	class Renderer
	{
	public:
		Renderer();
		virtual ~Renderer();

		static void Draw(GraphicsContext& context, VertexBuffer vb /* prototype */);
		static void Display(GraphicsContext& context);
	};

}