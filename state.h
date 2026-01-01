#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "digit.h"

namespace state {

  #define GRIDSZ 3

  class State {
    public:
      // digits[y][x]
      digit::Digit digits[GRIDSZ][GRIDSZ];

      std::string describe() const;

      State setValue(const int y, const int x, const digit::Digit newDigit) const;
  };

}

#endif
