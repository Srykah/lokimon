#pragma once

#include <nlohmann/json.hpp>
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
  COUNT  // keep last
};

NLOHMANN_JSON_SERIALIZE_ENUM(Element,
                             {
                                 {Element::NONE, nullptr},
                                 {Element::WATER, "WATER"},
                                 {Element::FIRE, "FIRE"},
                                 {Element::ICE, "ICE"},
                                 {Element::WIND, "WIND"},
                                 {Element::AURA, "AURA"},
                                 {Element::POISON, "POISON"},
                                 {Element::ELEC, "ELEC"},
                                 {Element::METAL, "METAL"},
                                 {Element::EARTH, "EARTH"},
                             })

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
  COUNT  // keep last
};

NLOHMANN_JSON_SERIALIZE_ENUM(Family,
                             {
                                 {Family::NONE, nullptr},
                                 {Family::BIRD, "BIRD"},
                                 {Family::INSECT, "INSECT"},
                                 {Family::PLANT, "PLANT"},
                                 {Family::REPT, "REPT"},
                                 {Family::BEAST, "BEAST"},
                                 {Family::DINO, "DINO"},
                                 {Family::DRAGON, "DRAGON"},
                             })

enum class Effectiveness {
  WORST = -2,
  BAD = -1,
  NORMAL = 0,
  GOOD = 1,
  BEST = 2,
};

NLOHMANN_JSON_SERIALIZE_ENUM(Effectiveness,
                             {
                                 {Effectiveness::NORMAL, "NORMAL"},
                                 {Effectiveness::WORST = "WORST"},
                                 {Effectiveness::BAD, "BAD"},
                                 {Effectiveness::GOOD, "GOOD"},
                                 {Effectiveness::BEST, "BEST"},
                             })

Effectiveness getEffectiveness(Element attackElement, Element defenderElement);
Effectiveness getEffectiveness(Family attackFamily, Family defenderFamily);
float getEffectivenessMultiplier(Effectiveness effectiveness);
float getEffectivenessMultiplier(Element attackElement,
                                 Element defenderElement);
float getEffectivenessMultiplier(Family attackFamily, Family defenderFamily);

}  // namespace mon
