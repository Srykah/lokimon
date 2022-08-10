/*!
 * \file PlayerMapStatus.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <SFML/System/Vector2.hpp>
#include "misc/Direction.hpp"

namespace mon {

struct PlayerMapStatus {
  std::string mapName;
  sf::Vector2i pos;
  Direction facing;
};

}  // namespace mon
