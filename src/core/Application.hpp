/*!
 * \file Application.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <loki/input/service/EventHandler.hpp>
#include <loki/screens/ScreenStack.hpp>
#include <loki/window/Window.hpp>
#include <models/data/GameData.hpp>
#include "ViewData.hpp"
#include "models/gameplay/Player.hpp"

namespace mon {

class Application {
 public:
  Application();
  void run();

 private:
  loki::window::Window window;
  loki::input::EventHandler eventHandler;
  loki::screens::ScreenStack stack;
  Player player;
  ViewData viewData;
  GameData gameData;

  friend class BaseScreen;
};

}
