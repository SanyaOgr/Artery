#pragma once
#include "graphics/BufferLayout.h"

namespace art {

	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void SetData(const void* data, uint32_t size) = 0;

		virtual const BufferLayout& GetLayout() const = 0;
		virtual void SetLayout(const BufferLayout& layout) = 0;

		static RefPtr<VertexBuffer> Create(uint32_t size);
		static RefPtr<VertexBuffer> Create(float* vertices, uint32_t size);
	};

}