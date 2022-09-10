#pragma once

#include <core/LokimonApplication.hpp>

#include <loki/system/screens/Screen.hpp>

namespace mon {

class BaseScreen : public loki::system::Screen {
 public:
  explicit BaseScreen(LokimonApplication& app);

  [[nodiscard]] Player& getPlayer();
  [[nodiscard]] const Player& getPlayer() const;
  [[nodiscard]] const loki::system::InputManager& getEventHandler() const;
  [[nodiscard]] const ViewData& getViewData() const;
  [[nodiscard]] const GameData& getGameData() const;

 protected:
  LokimonApplication& app;
};

}  // namespace mon
