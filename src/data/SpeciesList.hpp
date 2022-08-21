#pragma once

#include "Species.hpp"

namespace mon {

class SpeciesList {
 public:
  SpeciesList() = default;

  void load();
  [[nodiscard]] const Species& getSpecies(const std::string& id) const;

 private:
  std::unordered_map<std::string, Species> species;
};

}  // namespace mon
