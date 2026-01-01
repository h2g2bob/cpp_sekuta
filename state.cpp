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

State State::setValue(const int y, const int x, const Digit newDigit) const {
  assert(y >= 0 && y < GRIDSZ);
  assert(x >= 0 && x < GRIDSZ);

  State out {};

  // the dumb way to copy all the values:
  for (int iy = 0; iy < GRIDSZ; iy++) {
    for (int ix = 0; ix < GRIDSZ; ix++) {
      out.digits[iy][ix] = digits[iy][ix];
    }
  }
  out.digits[y][x] = newDigit;

  return out;
}
