#include <cassert>
#include <sstream>
#include "state.h"

using namespace state;
using digit::Digit;
using digit::digitFromSingleValue;

std::string State::describe() const {
  std::ostringstream out;
  out << "State";
  if (!this->isValid()) {
    out << " invalid";
  }
  out << ":\n";
  for (int y = 0; y < GRIDSZ; y++) {
    for (int x = 0; x < GRIDSZ; x++) {
      out << " " << digits[INDEX(y, x)].describe();
    }
    out << "\n";
  }
  return out.str();
}

State State::setValue(const int y, const int x, const Digit newDigit) const {
  assert(y >= 0 && y < GRIDSZ);
  assert(x >= 0 && x < GRIDSZ);

  State out = *this;
  out.digits[INDEX(y, x)] = newDigit;

  return out;
}

bool State::isValid() const {
  // no numbers possible for one square
  for (auto const digit : digits) {
    if (digit.bitmask == 0) {
      return false;
    }
  }

  // a number has no square it can fit into
  digit::Digit possible_bitmasks {0};
  for (auto const digit : digits) {
    possible_bitmasks.bitmask |= digit.bitmask;
  }
  if (possible_bitmasks.bitmask != ALL_OPTIONS) {
    return false;
  }

  return true;
}
