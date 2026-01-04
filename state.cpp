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
  for (auto const digit : digits) {
    if (digit.bitmask == 0) {
      return false;
    }
  }
  return true;
}
