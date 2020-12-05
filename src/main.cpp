#include <iostream>
#include "core/Application.hpp"

int main() {
  try {
    mon::Application app;
    app.run();
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
