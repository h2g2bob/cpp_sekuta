#include <iostream>
#include "digit.h"
#include "state.h"

using namespace std;
using namespace digit;
using namespace state;

void printDigit(string name, const Digit dig) {
  cout << name << " " << dig.describe() << "\n";
}

void printState(string name, const State state) {
  cout << name << " " << state.describe() << "\n";
}


int main(int argc, char *argv[]) {
  cout << "Hello world\n";

  const Digit digA = digitFromSingleValue(3);
  printDigit("digA", digA);

  const Digit digB {};
  printDigit("digB", digB);

  const State initState {};
  printState("initState", initState);

  const Digit testArray[3] = {
    digitFromSingleValue(9),
    // via constructor, explicit type:
    Digit {},
    // via constructor, type implied:
    {}};
  printDigit("testArray[0]", testArray[0]);
  printDigit("testArray[1]", testArray[1]);
  printDigit("testArray[2]", testArray[2]);

  const State updatedState = initState.setValue(1, 1, digA);
  printState("updatedState", updatedState);

  const State badState = initState.setValue(1, 1, Digit {0});
  printState("badState", badState);
}
