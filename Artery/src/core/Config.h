#pragma once

#if defined(_WIN32)

	#define ARTERY_SYSTEM_WINDOWS
	#ifndef NOMINMAX
		#define NOMINMAX
	#endif

	#define ARTERY_RENDERER_OPENGL

#endif

#if defined(_DEBUG)

#define ARTERY_DEBUG

#endif
