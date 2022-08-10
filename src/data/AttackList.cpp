/*!
 * \file AttackList.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "AttackList.hpp"
#include <fstream>
#include <loki/core/utils/IterAdapters.hpp>
#include "core/path.hpp"

namespace {

const std::string ATTACK_DATA_VERSION{"0.2"};

}

namespace mon {

void AttackList::load() {
  std::ifstream attackFile{DATA_PATH / "attacks.json"};
  nlohmann::json json;
  attackFile >> json;
  auto fileVersion =
      json.at("/meta/format_version"_json_pointer).get<std::string>();
  if (fileVersion != ATTACK_DATA_VERSION) {
    throw std::runtime_error{"Wrong attackCutscene file version : expected " +
                             ATTACK_DATA_VERSION + " but got " + fileVersion};
  }
  json.at("attacks").get_to(attacks);
  for (auto& [id, atk] : attacks) {
    atk.id = id;
  }
}

const Attack& mon::AttackList::getAttack(const std::string& id) const {
  return attacks.at(id);
}

}  // namespace mon
