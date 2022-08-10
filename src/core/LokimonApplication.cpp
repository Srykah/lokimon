/*!
 * \file Application.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "LokimonApplication.hpp"
#include "path.hpp"
#include "screens/battle/main/BattleScreen.hpp"

namespace {

const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);

}

namespace mon {

LokimonApplication::LokimonApplication() : player(gameData) {
  window.create({640, 360}, "Lokimon", loki::window::Style::DEFAULT);
  window.setInternalResolution({320, 180});
  window.setMinimumSize({320, 180});
  loki::input::InputSettings inputs;
  inputs.load(SAVES_PATH / "inputs.json");
  eventHandler.setSettings(std::move(inputs));
  eventHandler.setPlayerConfig(loki::input::PlayerConfig{"keyboard"});
  viewData.load();
  gameData.load();
  player.load();
  Trainer trainer{"BadGuy",
                  std::vector{Monster{"Glagla", "IceBeast", false, gameData}}};
  trainer.getMonster(0).setAttack(0, "IceShard");
  screenStack.push(std::make_unique<BattleScreen>(*this, std::move(trainer)));
}

void LokimonApplication::run() {
  sf::Clock clock;
  sf::Time timeSinceLastFrame;
  bool play = true;
  while (play) {
    timeSinceLastFrame += clock.restart();
    for (; timeSinceLastFrame >= TIME_PER_FRAME;
         timeSinceLastFrame -= TIME_PER_FRAME) {
      screenStack.update(TIME_PER_FRAME);
      sf::Event event;
      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          screenStack.sendSignal({{nullptr, "applicationClose"}});
          play = false;
        }
      }
      eventHandler.update(TIME_PER_FRAME);
      window.clear(sf::Color::Black);
      window.draw(screenStack);
      window.display();
    }
    sf::sleep((TIME_PER_FRAME - timeSinceLastFrame) / 2.f);
  }
}

}  // namespace mon
