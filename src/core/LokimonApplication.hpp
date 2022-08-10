/*!
 * \file Application.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <loki/system/app/Application.hpp>
#include "ViewData.hpp"
#include "data/GameData.hpp"
#include "gameplay/Player.hpp"

namespace mon {

class LokimonApplication : public loki::app::Application {
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
