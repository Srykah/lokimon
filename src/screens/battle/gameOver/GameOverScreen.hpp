/*!
 * \file GameOverScreen.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <screens/base/BaseScreen.hpp>
namespace mon {

class GameOverScreen : public BaseScreen {
 public:
  explicit GameOverScreen(Application& app);

  bool update(sf::Time delta) override;
  bool updateView(sf::Time delta) override;
  bool render(sf::RenderTarget& target, sf::RenderStates states) const override;
};

}
