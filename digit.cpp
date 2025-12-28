#include <sstream>
#include "digit.h"

using namespace digit;

Digit digit::digitFromSingleValue(int singleValue){
  return Digit {1 << singleValue};
}

int Digit::countOptions() const {
  int options = 0;
  for (int temp = bitmask; temp; temp = temp >> 1) {
    if (temp & 0x1) {
      options ++;
    }
  }
  return options;
}

int Digit::getData() const {
  return bitmask;
}

int Digit::getValue() const {
  for (int i = MIN; i <= MAX; i++) {
    if (bitmask == 1 << i) {
      return i;
    }
  }
  return 0;
}

std::string Digit::describe() const {
  std::ostringstream out;
  out << getData() << " (" << getValue() << ") has " << countOptions() << " options";
  return out.str();
}
