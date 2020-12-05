/*!
 * \file BaseScreen.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <core/Application.hpp>
#include <loki/screens/Screen.hpp>

namespace mon {

class BaseScreen : public loki::screens::Screen {
 public:
  explicit BaseScreen(Application& app);

  template<typename ScreenType, typename... Args>
  const ScreenType* pushState(Args&&... args) {
    auto ptr = std::make_unique<ScreenType>(app, std::forward<Args>(args)...);
    auto rawPtr = ptr.get();
    stack.push(std::move(ptr));
    return rawPtr;
  }
  void closeState(const Screen* screen);
  void closeStatesAbove();
  void closeThisState();
  void clearStates();
  void sendSignal(const std::string& signalName);
  template< typename... Args>
  void sendSignal(const std::string& signalName, Args&&... args) {
    // 0% chance it works on first try
    std::any value { std::make_tuple(std::forward<Args>(args)...) };
    stack.sendSignal({this, signalName, value});
  }

  [[nodiscard]] Player& getPlayer() const;
  [[nodiscard]] loki::input::EventHandler& getEventHandler();
  [[nodiscard]] const ViewData& getViewData() const;
  [[nodiscard]] const GameData& getGameData() const;

 private:
  Application& app;
};

}