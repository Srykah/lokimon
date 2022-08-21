#include "Trainer.hpp"

namespace mon {

Trainer::Trainer(std::string name, std::vector<Monster> monsters)
    : name(std::move(name)), monsters(std::move(monsters)) {}

}  // namespace mon