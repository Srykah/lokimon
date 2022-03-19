/*!
 * \file SpeciesList.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "SpeciesList.hpp"
#include <core/path.hpp>
#include <fstream>
#include <loki/core/utils/IterAdapters.hpp>

namespace mon {

const std::string SPECIES_DATA_VERSION{"0.2"};

void SpeciesList::load() {
  std::ifstream speciesFile{mon::DATA_PATH / "species.json"};
  nlohmann::json json;
  speciesFile >> json;
  auto fileVersion =
      json.at("/meta/format_version"_json_pointer).get<std::string>();
  if (fileVersion != SPECIES_DATA_VERSION) {
    throw std::runtime_error{"Wrong species file version : expected " +
                             SPECIES_DATA_VERSION + " but got " + fileVersion};
  }
  json.at("species").get_to(species);
  for (auto& [id, spec] : species) {
    spec.id = id;
  }
}

const Species& SpeciesList::getSpecies(std::string id) const {
  return species.at(id);
}

}  // namespace mon
