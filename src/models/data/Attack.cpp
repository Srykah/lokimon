/*!
 * \file Attack.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "Attack.hpp"

#include <core/path.hpp>
#include <fstream>
#include <loki/core/utils/IterAdapters.hpp>
#include <stdexcept>
#include <vector>

namespace mon {

void from_json(const nlohmann::json& j, Effect& e) {
  const auto& type = j.at("type").get<std::string>();
  if (type == "PHYSICAL") {
    e = j.get<PhysicalEffect>();
  } else if (type == "ELEMENTAL") {
    e = j.get<ElementalEffect>();
  } else {
    throw std::runtime_error("loadEffect error: effect type " + type +
                             " is not (yet) supported");
  }
}

}  // namespace mon
