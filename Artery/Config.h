#pragma once

#if defined(_WIN32)
	// Windows
	#define ARTERY_SYSTEM_WINDOWS
	#ifndef NOMINMAX
		#define NOMINMAX
	#endif
#endif
