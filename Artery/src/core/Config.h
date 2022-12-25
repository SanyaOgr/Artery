#pragma once

#if defined(_WIN32)

	#define ARTERY_SYSTEM_WINDOWS
	#ifndef NOMINMAX
		#define NOMINMAX
	#endif

	#define ARTERY_RENDERER_OPENGL

#endif

#if defined(ARTERY_DEBUG)
	
	#if defined(ARTERY_SYSTEM_WINDOWS)
		#define ART_DEBUGBREAK() __debugbreak()
	#else
		#define ART_DEBUGBREAK()
	#endif

	#define ARTERY_ENABLE_ASSERTS

#endif
