/*!
 * \file Direction.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <string>

namespace mon {

enum class Direction { UP, DOWN, LEFT, RIGHT };

std::string to_string(const Direction& dir);

}  // namespace mon
