#include <iostream>
#include "core/LokimonApplication.hpp"

int main() {
  try {
    mon::LokimonApplication app;
    app.run();
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
