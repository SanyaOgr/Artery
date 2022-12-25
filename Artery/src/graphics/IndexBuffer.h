#pragma once
#include "core/Base.h"

namespace art {

	// Currently Artery only supports 32-bit index buffers
	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual uint32_t GetCount() const = 0;

		static RefPtr<IndexBuffer> Create(uint32_t* indices, uint32_t count);
	};

}