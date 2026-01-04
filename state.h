#ifndef STATE_H
#define STATE_H

#include <array>
#include <iostream>
#include "digit.h"

namespace state {

  #define GRIDSZ 3
  #define INDEX(Y, X) (Y*GRIDSZ + X)

  class State {
    public:
      // digits[y][x]
      std::array<digit::Digit, GRIDSZ*GRIDSZ> digits;

      std::string describe() const;

      digit::Digit getDigit(const int y, const int x) const;
      State setDigit(const int y, const int x, const digit::Digit newDigit) const;
      bool isValid() const;
  };

}

#endif
