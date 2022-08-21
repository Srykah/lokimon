#pragma once

namespace mon {

float getDeltaMultiplier(int delta) {
  return (3.f + std::max(delta, 0)) / (3.f + std::max(-delta, 0));
}

}  // namespace mon
