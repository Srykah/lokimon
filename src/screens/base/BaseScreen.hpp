/*!
 * \file BaseScreen.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <core/LokimonApplication.hpp>
#include <loki/system/screens/Screen.hpp>

namespace mon {

class BaseScreen : public loki::screens::Screen {
 public:
  explicit BaseScreen(LokimonApplication& app);

  [[nodiscard]] Player& getPlayer();
  [[nodiscard]] const Player& getPlayer() const;
  [[nodiscard]] const loki::input::EventHandler& getEventHandler() const;
  [[nodiscard]] const ViewData& getViewData() const;
  [[nodiscard]] const GameData& getGameData() const;

 protected:
  [[nodiscard]] loki::screens::ScreenStack& getScreenStack() override;

  LokimonApplication& app;
};

}  // namespace mon
