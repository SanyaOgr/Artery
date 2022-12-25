#pragma once

#define ART_EXPAND_MACRO(x) x
#define ART_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define ART_FORWARD_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }
