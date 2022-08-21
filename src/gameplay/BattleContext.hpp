#pragma once

#include <loki/core/tpl/TemplateEngine.hpp>
#include <loki/gui/elements/TextBox.hpp>

#include "Monster.hpp"
#include "Trainer.hpp"

namespace mon {

struct BattleContext {
  Trainer opponent;
  Monster* playerMonster = nullptr;
  Monster* opponentMonster = nullptr;
  const Attack* playerMove = nullptr;
  const Attack* opponentMove = nullptr;
  loki::core::TemplateEngine tpl;
  loki::gui::TextBox textBox;
};

}  // namespace mon
