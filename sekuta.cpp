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

void solve(const State state) {
  printState("solve", state);
  if (!state.isValid()) {
    return;
  }

  for (int y = 0; y < GRIDSZ; y++) {
    for (int x = 0; x < GRIDSZ; x++) {
      const Digit digit = state.getDigit(y, x);
      if (digit.countOptions() > 1) {
        for (int possValue : digit.possibleValues()) {
          const State newState = state.setDigit(y, x, digitFromSingleValue(possValue));
          solve(newState);
        }
      }
    }
  }
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

  const State updatedState = initState.setDigit(1, 1, digA);
  printState("updatedState", updatedState);

  const State badState = initState.setDigit(1, 1, Digit {0});
  printState("badState", badState);

  const State testState = initState \
    .setDigit(0, 0, digitFromSingleValue(1)) \
    .setDigit(0, 1, digitFromSingleValue(2)) \
    .setDigit(0, 2, digitFromSingleValue(3)) \
    .setDigit(1, 0, digitFromSingleValue(4)) \
    .setDigit(1, 1, digitFromSingleValue(5)) \
    .setDigit(1, 2, digitFromSingleValue(6));
  cout << "\nSolve\n";
  solve(testState);
}
