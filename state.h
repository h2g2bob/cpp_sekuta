#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "digit.h"

namespace state {

  #define GRIDSZ 3

  class State {
    public:
      digit::Digit digits[GRIDSZ][GRIDSZ];

      std::string describe() const;
  };

}

#endif
