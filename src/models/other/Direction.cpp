/*!
 * \file Direction.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "Direction.hpp"

#include <stdexcept>

namespace mon {

std::string to_string(const Direction& dir) {
  switch (dir) {
    case Direction::UP:
      return "up";
    case Direction::DOWN:
      return "down";
    case Direction::LEFT:
      return "left";
    case Direction::RIGHT:
      return "right";
  }
  throw std::logic_error(
      "Invalid value for Direction of internal value: " +
      std::to_string(static_cast<std::underlying_type_t<Direction>>(dir)));
}

}  // namespace mon
