/*!
 * \file ViewData.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "ViewData.hpp"
#include <fstream>
#include "core/path.hpp"

namespace mon {

ViewData::ViewData() : playerSpriteData("assets/sprites/player/player.json") {}

void ViewData::load() {
  defaultFont.loadFromFile("assets/fonts/corbell.ttf");

  loki::text::AnimatedTextStyle defaultStyle;
  defaultStyle.font = &defaultFont;
  defaultStyle.characterSize = 15;
  textStylesheet.setDefaultStyle(defaultStyle);

  i18nData.loadFromFile(DATA_PATH / "lang" / "lang_list.json");
  i18nData.setCurLang("en-us");
}

const sf::Font& ViewData::getDefaultFont() const {
  return *textStylesheet.getDefaultStyle().font.value();
}

void ViewData::setLang(const std::string& langId) {
  i18nData.setCurLang(langId);
}
const std::string& ViewData::getCurLangId() const {
  return i18nData.getCurLangId();
}

std::string ViewData::getI18nStr(
    const nlohmann::json_pointer<nlohmann::json>& ptr) const {
  return i18nData.getCurLang().at(ptr).get<std::string>();
}

const loki::text::Stylesheet& ViewData::getTextStylesheet() const {
  return textStylesheet;
}

const loki::text::AnimatedTextStyle& ViewData::getDefaultTextStyle() const {
  return textStylesheet.getDefaultStyle();
}

const loki::sprites::SpriteData& ViewData::getPlayerSpriteData() const {
  return playerSpriteData;
}

}  // namespace mon
