/*!
 * \file TranslatedStrings.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <SFML/System/String.hpp>
#include <map>
#include <nlohmann/json.hpp>
#include <string>

namespace mon {

using TranslatedString = std::map<std::string, sf::String>;

TranslatedString loadTranslatedString(const nlohmann::json& data);

}