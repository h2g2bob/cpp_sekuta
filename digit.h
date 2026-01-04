#ifndef DIGIT_H
#define DIGIT_H

#include <bitset>
#include <iostream>
#include <vector>

namespace digit {

  #define MIN 1
  #define MAX 9
  #define ALL_OPTIONS 0b1111111110

  class Digit {

  public:
    std::bitset<MAX+1>bitmask = ALL_OPTIONS;

    int countOptions() const;
    int getValue() const;
    std::string describe() const;
    std::vector<int> possibleValues() const;
  };


  Digit digitFromSingleValue(int singleValue);

}

#endif
