#pragma once

#include <memory>

namespace art {

#define ART_FORWARD_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

}