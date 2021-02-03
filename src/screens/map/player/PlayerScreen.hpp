/*!
 * \file PlayerScreen.hpp.h
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <screens/base/BaseScreen.hpp>
#include "../main/MapScreenView.hpp"

namespace mon {

class PlayerScreen : public BaseScreen {
 public:
  PlayerScreen(Application& app,
               const loki::tiles::MapData& mapData,
               MapScreenView& view);
  ~PlayerScreen() override = default;
  void init() override;

  bool update(sf::Time delta) override;
  bool updateView(sf::Time delta) override;
  bool render(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  const loki::tiles::MapData& mapData;
  MapScreenView& view;
};

}  // namespace mon
