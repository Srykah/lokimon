/*!
 * \file Application.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "Application.hpp"
#include <screens/battle/main/BattleScreen.hpp>
#include "path.hpp"

namespace {

const sf::Time TIME_PER_FRAME = sf::seconds(1.f/60.f);

}

namespace mon {

Application::Application()
    : window({640, 360},
             "Lokimon",
             loki::window::Style::TITLEBAR | loki::window::Style::CLOSE |
                 loki::window::Style::INTEGER_ZOOM_RATIO),
      eventHandler(),
      player(gameData) {
  loki::input::InputSettings inputs;
  inputs.load(SAVES_PATH / "inputs.json");
  eventHandler.setSettings(std::move(inputs));
  eventHandler.setPlayerConfig(loki::input::PlayerConfig {"keyboard"});
  viewData.load();
  gameData.load();
  player.load();
  Trainer trainer{"BadGuy",
                  std::vector{Monster{"Glagla", SpeciesIndex{2}, false, gameData}}};
  trainer.getMonster(0)->setAttack(0, AttackIndex{2});
  stack.push(std::make_unique<BattleScreen>(*this, std::move(trainer)));
}

void Application::run() {
  sf::Clock clock;
  sf::Time timeSinceLastFrame;
  while (!stack.empty()) {
    timeSinceLastFrame += clock.restart();
    for (;timeSinceLastFrame >= TIME_PER_FRAME; timeSinceLastFrame -= TIME_PER_FRAME) {
      stack.update(TIME_PER_FRAME);
      sf::Event event;
      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          stack.clear();
        }
      }
      eventHandler.update(TIME_PER_FRAME);
      window.clear(sf::Color::Black);
      window.draw(stack);
      window.display();
    }
    sf::sleep((TIME_PER_FRAME - timeSinceLastFrame) / 2.f);
  }
}

}  // namespace mon
