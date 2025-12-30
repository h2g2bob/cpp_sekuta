#include <sstream>
#include "state.h"

using namespace state;

std::string State::describe() const {
  std::ostringstream out;
  out << "State:\n";
  for (int y = 0; y < GRIDSZ; y++) {
    for (int x = 0; x < GRIDSZ; x++) {
      out << " " << digits[y][x].describe();
    }
    out << "\n";
  }
  return out.str();
}
