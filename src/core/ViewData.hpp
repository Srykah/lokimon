/*!
 * \file ViewData.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <SFML/Graphics/Font.hpp>
#include <loki/graphics/styles/TextStyle.hpp>
#include <loki/graphics/text/Stylesheet.hpp>
#include <loki/strings/i18n/I18nData.hpp>

namespace mon {

class ViewData {
 public:
  using I18nPtr = nlohmann::json_pointer<nlohmann::json>;

 public:
  explicit ViewData();

  void load();

  [[nodiscard]] const loki::text::Stylesheet& getTextStylesheet() const;
  [[nodiscard]] const loki::text::AnimatedTextStyle& getDefaultTextStyle()
      const;
  [[nodiscard]] const sf::Font& getDefaultFont() const;

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
  loki::text::Stylesheet textStylesheet;
  loki::i18n::I18nData i18nData;
};

}
