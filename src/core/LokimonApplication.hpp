#pragma once

#include <loki/system/app/Application.hpp>
#include "ViewData.hpp"
#include "data/GameData.hpp"
#include "gameplay/Player.hpp"

namespace mon {

class LokimonApplication : public loki::system::Application {
 public:
  LokimonApplication();
  void run();

 private:
  Player player;
  ViewData viewData;
  GameData gameData;

  friend class BaseScreen;
};

}  // namespace mon
