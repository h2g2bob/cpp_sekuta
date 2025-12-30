#include <cassert>
#include <sstream>
#include "state.h"

using namespace state;
using digit::Digit;
using digit::digitFromSingleValue;

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

void State::setSingleValue(int y, int x, int singleValue) {
  assert(y >= 0 && y < GRIDSZ);
  assert(x >= 0 && x < GRIDSZ);
  // ...?
  // Digit value = digitFromSingleValue(singleValue);
  // digits[y][x] = value;
}
