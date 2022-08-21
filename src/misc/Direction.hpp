#pragma once

#include <string>

namespace mon {

enum class Direction { UP, DOWN, LEFT, RIGHT };

std::string to_string(const Direction& dir);

}  // namespace mon
