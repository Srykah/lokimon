#include "ViewData.hpp"
#include <fstream>
#include "core/path.hpp"

namespace mon {

ViewData::ViewData() : playerSpriteData("assets/gfx/player/player.json") {}

void ViewData::load() {
  defaultFont.loadFromFile("assets/fonts/corbell.ttf");

  loki::gfx::AnimatedTextStyle defaultStyle;
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

const loki::gfx::Stylesheet& ViewData::getTextStylesheet() const {
  return textStylesheet;
}

const loki::gfx::AnimatedTextStyle& ViewData::getDefaultTextStyle() const {
  return textStylesheet.getDefaultStyle();
}

const loki::gfx::SpriteData& ViewData::getPlayerSpriteData() const {
  return playerSpriteData;
}

}  // namespace mon
