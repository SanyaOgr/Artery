#pragma once
#include "Log.h"

#ifdef _DEBUG
	
#define DLOG(text) util::Logger::Instance()->Log(text)
#define ASSERT(x) if(!(x)) __debugbreak()

#else

#define DLOG(text)
#define ASSERT(x)

#endif // _DEBUG


#define LOG(text) util::Logger::Instance()->Log(text)