#include "LokimonApplication.hpp"

#include "path.hpp"

namespace mon {

LokimonApplication::LokimonApplication() : player(gameData) {}

void LokimonApplication::init() {
  window.setInternalResolution({320, 180});
  window.setMinimumSize({320, 180});
  window.create({640, 360}, "Lokimon", loki::system::WindowStyle::DEFAULT);
  inputManager.loadConfigs(SAVES_PATH / "lokimon.inputs.json");
  inputManager.setPlayerConfig({"keyboard", loki::system::InputMethod::KeyboardAndMouse});
  viewData.load();
  gameData.load();
  player.load();
  /*
  Trainer trainer{"BadGuy",
                  std::vector{Monster{"Glagla", "IceBeast", false, gameData}}};
  trainer.getMonster(0).setAttack(0, "IceShard");
   */
}

}  // namespace mon

std::unique_ptr<loki::system::Application> getApplication() {
  return std::make_unique<mon::LokimonApplication>();
}
