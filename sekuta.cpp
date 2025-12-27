#include <iostream>
#include "digit.h"

using namespace std;
using namespace digit;

// class State {
//  a, b, c, d, e, f, g, h, i: int

void printDigit(string name, Digit dig) {
  cout << name << " " << dig.getData() << " (" << dig.getValue() << ") has " << dig.countOptions() << " options\n";
}

int main(int argc, char *argv[]) {
  cout << "Hello world\n";

  const Digit digA = digitFromSingleValue(3);
  printDigit("digA", digA);

  const Digit digB {};
  printDigit("digB", digB);
}
