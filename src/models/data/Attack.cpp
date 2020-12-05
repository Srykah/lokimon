/*!
 * \file Attack.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "Attack.hpp"
#include <core/path.hpp>
#include <fstream>
#include <loki/common/IterAadapters.hpp>
#include <stdexcept>
#include <vector>

namespace {

mon::Attack::Range getRangeFromString(const std::string& str) {
#define CHECK_RANGE_STR(rangeStr)        \
  if (str == #rangeStr) {                \
    return mon::Attack::Range::rangeStr; \
  }
  // clang-format off
  CHECK_RANGE_STR(SELF)
  else CHECK_RANGE_STR(ALLY)
  else CHECK_RANGE_STR(ALLIES)
  else CHECK_RANGE_STR(ENEMY)
  else CHECK_RANGE_STR(ENEMIES)
  else CHECK_RANGE_STR(TARGET)
  else CHECK_RANGE_STR(ALL)
  else throw std::runtime_error("getRangeFromString error: " + str +
                    " is not a valid Attack::Range value");
  // clang-format on
#undef CHECK_RANGE_STR
}

mon::Attack::Effect loadEffect(const nlohmann::json& effectData) {
  const auto& type = effectData.at("type").get<std::string>();
  if (type == "PHYSICAL") {
    return mon::PhysicalEffect{
        effectData.at("power").get<int>(), effectData.at("crit").get<int>(),
        effectData.at("fail").get<int>(),
        mon::getFamilyFromString(effectData.at("family").get<std::string>())};
  } else if (type == "ELEMENTAL") {
    return mon::ElementalEffect{
        effectData.at("power").get<int>(), effectData.at("crit").get<int>(),
        effectData.at("fail").get<int>(),
        mon::getElementFromString(effectData.at("element").get<std::string>())};
  } else {
    throw std::runtime_error("loadEffect error: effect type " + type +
                             " is not (yet) supported");
  }
}

}  // namespace

namespace mon {

void Attack::load(const nlohmann::json& attackData) {
  names = loadTranslatedString(attackData.at("names"));
  descriptions = loadTranslatedString(attackData.at("descriptions"));
  range = getRangeFromString(attackData.at("range").get<std::string>());
  cost = attackData.at("cost").get<int>();
  speed = attackData.at("speed").get<int>();
  effects.reserve(attackData.at("effects").size());
  for (auto& effectData : attackData.at("effects")) {
    effects.emplace_back(loadEffect(effectData));
  }
}

}  // namespace mon
