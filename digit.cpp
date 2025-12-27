#include "digit.h"

using namespace digit;

Digit digit::digitFromSingleValue(int singleValue){
  return Digit {1 << singleValue};
}

int Digit::countOptions() const {
  int options = 0;
  for (int temp = data; temp; temp = temp >> 1) {
    if (temp & 0x1) {
      options ++;
    }
  }
  return options;
}

int Digit::getData() const {
  return data;
}

int Digit::getValue() const {
  for (int i = MIN; i <= MAX; i++) {
    if (data == 1 << i) {
      return i;
    }
  }
  return 0;
}
