#pragma once

#include <SFML/Graphics/Font.hpp>

#include <loki/core/i18n/I18nData.hpp>
#include <loki/graphics/sprites/SpriteData.hpp>
#include <loki/graphics/styles/TextStyle.hpp>
#include <loki/graphics/text/Stylesheet.hpp>

namespace mon {

class ViewData {
 public:
  using I18nPtr = nlohmann::json_pointer<nlohmann::json>;

 public:
  explicit ViewData();

  void load();

  [[nodiscard]] const loki::gfx::Stylesheet& getTextStylesheet() const;
  [[nodiscard]] const loki::gfx::AnimatedTextStyle& getDefaultTextStyle() const;
  [[nodiscard]] const sf::Font& getDefaultFont() const;
  [[nodiscard]] const loki::gfx::SpriteData& getPlayerSpriteData() const;

  void setLang(const std::string& langId);
  [[nodiscard]] const std::string& getCurLangId() const;
  [[nodiscard]] std::string getI18nStr(const I18nPtr& ptr) const;
  template <class... Args>
  [[nodiscard]] std::string getI18nStr(const std::string& uri,
                                       Args&&... args) const {
    return i18nData.get(uri, std::forward<Args>(args)...);
  }

 private:
  sf::Font defaultFont;
  loki::gfx::Stylesheet textStylesheet;
  loki::core::I18nData i18nData;
  loki::gfx::SpriteData playerSpriteData;
};

}  // namespace mon
