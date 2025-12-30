#ifndef DIGIT_H
#define DIGIT_H

#include <iostream>

namespace digit {

  #define MIN 1
  #define MAX 9
  #define ALL_OPTIONS 0b1111111110

  class Digit {

  public:
    int bitmask = ALL_OPTIONS;

    int countOptions() const;
    int getData() const;
    int getValue() const;
    std::string describe() const;
  };


  Digit digitFromSingleValue(int singleValue);

}

#endif
