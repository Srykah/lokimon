/*!
 * \file ViewData.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <SFML/Graphics/Font.hpp>
#include <loki/styles/TextStyle.hpp>

namespace mon {

class ViewData {
 public:
  void load();

  [[nodiscard]] const sf::Font& getDefaultFont() const {
    return defaultFont;
  }

  const loki::styles::TextStyle& getTextStyle() const;

 private:
  sf::Font defaultFont;
  loki::styles::TextStyle textStyle;
};

}
