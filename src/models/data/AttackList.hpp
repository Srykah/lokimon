/*!
 * \file AttackList.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <nlohmann/json.hpp>
#include "Attack.hpp"

namespace mon {

enum class AttackIndex : int { NONE = -1 };

class AttackList {
 public:
  AttackList() = default;

  void load();
  [[nodiscard]] const Attack& getAttack(AttackIndex index) const;

 private:
  std::vector<mon::Attack> attacks;
};

}
