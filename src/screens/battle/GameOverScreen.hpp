#pragma once

#include "gameplay/BattleContext.hpp"
#include "screens/base/BaseScreen.hpp"

namespace mon {

class GameOverScreen : public BaseScreen {
 public:
  explicit GameOverScreen(LokimonApplication& app, BattleContext& ctx);
  ~GameOverScreen() override = default;

  bool update(sf::Time delta) override;
  bool render(sf::RenderTarget& target, sf::RenderStates states) const override;
};

}  // namespace mon
