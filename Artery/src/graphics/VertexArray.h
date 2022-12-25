#pragma once

#include "graphics/VertexBuffer.h"
#include "graphics/IndexBuffer.h"

#include <memory>

namespace art {

	class VertexBuffer;
	class IndexBuffer;

	class VertexArray
	{
	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void AddVertexBuffer(const RefPtr<VertexBuffer>& vertexBuffer) = 0;
		virtual void SetIndexBuffer(const RefPtr<IndexBuffer>& indexBuffer) = 0;

		virtual const std::vector< RefPtr<VertexBuffer> >& GetVertexBuffers() const = 0;
		virtual const RefPtr<IndexBuffer>& GetIndexBuffer() const = 0;

		static RefPtr<VertexArray> Create();

	private:


	};

}