/*!
 * \file SpeciesList.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "SpeciesList.hpp"
#include <core/path.hpp>
#include <fstream>
#include <loki/common/IterAdapters.hpp>

namespace mon {

const std::string SPECIES_DATA_VERSION{"0.1"};

void SpeciesList::load() {
  std::ifstream speciesFile{mon::DATA_PATH / "species.json"};
  nlohmann::json json;
  speciesFile >> json;
  auto fileVersion = json.at("meta").at("version").get<std::string>();
  if (fileVersion != SPECIES_DATA_VERSION) {
    throw std::runtime_error{"Wrong species file version : expected " +
                             SPECIES_DATA_VERSION + " but got " + fileVersion};
  }
  species.resize(json.at("species").size());
  for (auto&& [spec, specData] :
       loki::common::zip(species, json.at("species"))) {
    spec.load(specData);
  }
}

const Species& SpeciesList::getSpecies(SpeciesIndex index) const {
  return species.at(static_cast<unsigned int>(index));
}

}  // namespace mon
