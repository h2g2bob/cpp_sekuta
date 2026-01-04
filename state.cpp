#include <array>
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

void unsetFromOtherSquares(State &state, Digit newDigit, std::size_t newDigitIndex) {
  for (std::size_t i = 0; i < state.digits.size(); i++) {
    if (i != newDigitIndex) {
      if ((state.digits[i].bitmask & newDigit.bitmask) != 0) {
        state.digits[i].bitmask &= ~newDigit.bitmask;
        if (state.digits[i].bitmask.count() == 1) {
          unsetFromOtherSquares(state, state.digits[i], i);
        }
      }
    }
  }
}

State State::setValue(const int y, const int x, const Digit newDigit) const {
  assert(y >= 0 && y < GRIDSZ);
  assert(x >= 0 && x < GRIDSZ);

  State out = *this;
  out.digits[INDEX(y, x)] = newDigit;

  if (newDigit.countOptions() == 1) {
    unsetFromOtherSquares(out, newDigit, INDEX(y, x));
  }

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
