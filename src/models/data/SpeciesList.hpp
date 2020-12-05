/*!
 * \file SpeciesList.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include "Species.hpp"

namespace mon {

enum class SpeciesIndex : unsigned int;

class SpeciesList {
 public:
  SpeciesList() = default;

  void load();
  [[nodiscard]] const Species& getSpecies(SpeciesIndex index) const;

 private:
  std::vector<Species> species;
};

}
