/*!
 * \file BattleContext.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <loki/gui/widgets/elements/textBox/TextBox.hpp>
#include <loki/strings/tpl/TemplateEngine.hpp>

#include "Monster.hpp"
#include "Trainer.hpp"

namespace mon {

struct BattleContext {
  Trainer opponent;
  Monster* playerMonster = nullptr;
  Monster* opponentMonster = nullptr;
  const Attack* playerMove = nullptr;
  const Attack* opponentMove = nullptr;
  loki::tpl::TemplateEngine tpl;
  loki::gui::TextBox textBox;
};

}  // namespace mon
