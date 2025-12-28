#ifndef DIGIT_H
#define DIGIT_H

#include <iostream>

namespace digit {

  #define MIN 1
  #define MAX 9
  #define ALL_OPTIONS 0b1111111110

  class Digit {

  public:
    const int bitmask;

    Digit(): bitmask{ALL_OPTIONS} {};
    Digit(int bitmask_): bitmask {bitmask_} {};

    int countOptions() const;
    int getData() const;
    int getValue() const;
    std::string describe() const;
  };


  Digit digitFromSingleValue(int singleValue);

}

#endif
