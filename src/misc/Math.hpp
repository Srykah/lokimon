/*!
 * \file Math.hpp.h
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

namespace mon {

float getDeltaMultiplier(int delta) {
  return (3.f + std::max(delta, 0)) / (3.f + std::max(-delta, 0));
}

}  // namespace mon
