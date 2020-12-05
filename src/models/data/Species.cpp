/*!
 * \file Species.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */

#include "Species.hpp"
#include <core/path.hpp>
#include <fstream>
#include <loki/common/IterAadapters.hpp>

namespace mon {

void Species::load(const nlohmann::json& speciesData) {
  names = loadTranslatedString(speciesData.at("names"));
  baseStats.load(speciesData.at("baseStats"));
  element = getElementFromString(speciesData.at("element").get<std::string>());
  family = getFamilyFromString(speciesData.at("family").get<std::string>());
  availableAttacksPerLevel.reserve(speciesData.at("attacks").size());
  for (const auto& pair : speciesData.at("attacks")) {
    availableAttacksPerLevel.emplace_back(
        pair.at(0).get<unsigned int>(),
        AttackIndex(pair.at(1).get<unsigned int>()));
  }
}

}  // namespace mon