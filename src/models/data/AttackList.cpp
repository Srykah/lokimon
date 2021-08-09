/*!
 * \file AttackList.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "AttackList.hpp"
#include <core/path.hpp>
#include <fstream>
#include <loki/common/IterAdapters.hpp>

namespace {
const std::string ATTACK_DATA_VERSION{"0.1"};
}

namespace mon {

void AttackList::load() {
  std::ifstream attackFile{DATA_PATH / "attacks.json"};
  nlohmann::json json;
  attackFile >> json;
  auto fileVersion = json.at("meta").at("version").get<std::string>();
  if (fileVersion != ATTACK_DATA_VERSION) {
    throw std::runtime_error{"Wrong attack file version : expected " +
                             ATTACK_DATA_VERSION + " but got " + fileVersion};
  }
  attacks.resize(json.at("attacks").size());
  for (auto&& [attack, attackData] :
       loki::common::zip(attacks, json.at("attacks"))) {
    attack.load(attackData);
  }
}

const Attack& mon::AttackList::getAttack(AttackIndex index) const {
  if (index == AttackIndex::NONE) {
    throw std::out_of_range("AttackIndex::NONE has no associated attack!");
  }
  return attacks.at(static_cast<int>(index));
}

}  // namespace mon
