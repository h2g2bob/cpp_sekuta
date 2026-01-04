#include <sstream>
#include <vector>
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

int Digit::min() const {
  for (int i = MIN; i <= MAX; i++) {
    if (bitmask[i]) {
      return i;
    }
  }
  return 0;
}

int Digit::max() const {
  for (int i = MAX; i >= MIN; i--) {
    if (bitmask[i]) {
      return i;
    }
  }
  return 0;
}

std::vector<int> Digit::possibleValues() const {
  std::vector<int> out {};
  for (int i = MIN; i <= MAX; i++) {
    if (bitmask[i]) {
      out.push_back(i);
    }
  }
  return out;
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
