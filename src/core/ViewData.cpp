/*!
 * \file ViewData.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "ViewData.hpp"

namespace mon {

void ViewData::load() {
  defaultFont.loadFromFile("assets/fonts/corbell.ttf");
  textStyle.font = &defaultFont;
}

const loki::styles::TextStyle& ViewData::getTextStyle() const {
  return textStyle;
}

}
