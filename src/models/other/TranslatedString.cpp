/*!
 * \file TranslatedString.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "TranslatedString.hpp"

namespace mon {

TranslatedString loadTranslatedString(const nlohmann::json& data) {
  TranslatedString translatedString;
  for (const auto& [lang, translationData] : data.items()) {
    auto translationStr = translationData.get<std::string>();
    translatedString.emplace(lang, sf::String::fromUtf8(translationStr.begin(),
                                                        translationStr.end()));
  }
  return translatedString;
}

}  // namespace mon