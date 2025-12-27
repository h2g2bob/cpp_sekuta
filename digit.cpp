#include "digit.h"

using namespace digit;

Digit digit::digitFromSingleValue(int singleValue){
  return Digit {1 << singleValue};
}
