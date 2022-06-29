/*!
 * \file SpeciesList.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include "Species.hpp"

namespace mon {

class SpeciesList {
 public:
  SpeciesList() = default;

  void load();
  [[nodiscard]] const Species& getSpecies(std::string id) const;

 private:
  std::unordered_map<std::string, Species> species;
};

}
