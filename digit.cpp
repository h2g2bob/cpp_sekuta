#include <sstream>
#include "digit.h"

using namespace digit;

Digit digit::digitFromSingleValue(int singleValue){
  return Digit {1 << singleValue};
}

int Digit::countOptions() const {
  return bitmask.count();
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
  out << "[";
  for (int i = MIN; i <= MAX; i++) {
    if (bitmask[i]) {
      out << i;
    } else {
      out << "-";
    }
  }
  out << "]";
  return out.str();
}
