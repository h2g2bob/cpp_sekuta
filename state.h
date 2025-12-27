#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "digit.h"

namespace state {

  class State {
    public:
      digit::Digit a, b, c, d, e, f, g, h, i;

      std::string describe() const;
  };

}

#endif
