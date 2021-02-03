/*!
 * \file MapScreenView.hpp.h
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>
#include <loki/tiles/All.hpp>

namespace mon {

class MapScreenView : public sf::Drawable {
 public:
  MapScreenView() = default;

  void update(sf::Time delta);
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

  void setMapData(const loki::tiles::MapData& data);

 private:
  loki::tiles::MapView mapView;
};

}  // namespace mon
