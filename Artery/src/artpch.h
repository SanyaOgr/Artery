#pragma once

#include "core/Base.h"

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#if defined(ARTERY_SYSTEM_WINDOWS)
	#include <Windows.h>
#endif

#if defined(ARTERY_RENDERER_OPENGL)
	#include <glad/glad.h>
#endif