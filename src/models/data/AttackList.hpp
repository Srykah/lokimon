/*!
 * \file AttackList.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <nlohmann/json.hpp>
#include "Attack.hpp"

namespace mon {

class AttackList {
 public:
  AttackList() = default;

  void load();
  [[nodiscard]] const Attack& getAttack(std::string id) const;

 private:
  std::unordered_map<std::string, mon::Attack> attacks;
};

}
