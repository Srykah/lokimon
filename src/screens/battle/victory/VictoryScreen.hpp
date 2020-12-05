/*!
 * \file VictoryScreen.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <screens/base/BaseScreen.hpp>
namespace mon {

class VictoryScreen : public BaseScreen {
 public:
  explicit VictoryScreen(Application& app);

  bool update(sf::Time delta) override;
  bool updateView(sf::Time delta) override;
  bool render(sf::RenderTarget& target, sf::RenderStates states) const override;
};

}
