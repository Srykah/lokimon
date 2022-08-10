/*!
 * \file GameData.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <loki/graphics/tiles/model/MapData.hpp>
#include "models/data/AttackList.hpp"
#include "models/data/SpeciesList.hpp"

namespace mon {

class GameData {
 public:
  void load();
  [[nodiscard]] const Species& getSpecies(const std::string& id) const;
  [[nodiscard]] const Attack& getAttack(const std::string& id) const;
  [[nodiscard]] const loki::tiles::MapData& getMap(const std::string& id) const;

 private:
  SpeciesList speciesList;
  AttackList attackList;
};

}  // namespace mon
