/*!
 * \file MapScreenView.cpp.c
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "MapScreenView.hpp"

namespace mon {

void MapScreenView::update(sf::Time delta) {
  mapView.update(delta);
}

void MapScreenView::draw(sf::RenderTarget& target,
                         sf::RenderStates states) const {
  for (const auto& layer : mapView.getLayers()) {
    target.draw(*layer, states);
  }
}

void MapScreenView::setMapData(const loki::tiles::MapData& data) {
  mapView.setData(data);
}

}  // namespace mon
