#include <iostream>
#include "digit.h"

using namespace std;
using namespace digit;

// class State {
//  a, b, c, d, e, f, g, h, i: int


int main(int argc, char *argv[]) {
  cout << "Hello world\n";

  const Digit digA = digitFromSingleValue(3);
  cout << "DigitA " << digA.getData() << " (" << digA.getValue() << ") has " << digA.countOptions() << " options\n";

  const Digit digB {};
  cout << "DigitB " << digB.getData() << " (" << digB.getValue() << ") has " << digB.countOptions() << " options\n";
}
