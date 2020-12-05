/*!
 * \file Elements.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <string>

namespace mon {

// DO NOT CHANGE THE ORDER!!!
// (or remember to change the effectiveness map in Elements.cpp!)
enum class Element {
  NONE = -1,
  WATER,
  FIRE,
  ICE,
  WIND,
  AURA,
  POISON,
  ELEC,
  METAL,
  EARTH,
  COUNT // keep last
};

// DO NOT CHANGE THE ORDER!!!
// (or remember to change the effectiveness map in Elements.cpp!)
enum class Family {
  NONE = -1,
  BIRD,
  INSECT,
  PLANT,
  REPT,
  BEAST,
  DINO,
  DRAGON,
  COUNT // keep last
};

enum class Effectiveness {
  WORST = -2,
  BAD = -1,
  NORMAL = 0,
  GOOD = 1,
  BEST = 2,
};

Element getElementFromString(const std::string& str);
Family getFamilyFromString(const std::string& str);
Effectiveness getEffectiveness(Element attackElement, Element defenderElement);
Effectiveness getEffectiveness(Family attackFamily, Family defenderFamily);

}
