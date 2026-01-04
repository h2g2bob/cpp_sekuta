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

bool constraintOk(const State state, int y1, int y2, int x1, int x2, int expectValue) {
  int max = \
    state.getDigit(y1, x1).max() +
    state.getDigit(y1, x2).max() +
    state.getDigit(y2, x1).max() +
    state.getDigit(y2, x2).max();
  int min = \
    state.getDigit(y1, x1).min() +
    state.getDigit(y1, x2).min() +
    state.getDigit(y2, x1).min() +
    state.getDigit(y2, x2).min();
  return (min <= expectValue) && (max >= expectValue);
}

bool constraintsOk(const State state) {
  return \
    constraintOk(state, 0, 1, 0, 1, 27) &&
    constraintOk(state, 0, 1, 1, 2, 16) &&
    constraintOk(state, 1, 2, 0, 1, 28) &&
    constraintOk(state, 1, 2, 1, 2, 17);
}

void solve(const State state) {
  if (!state.isValid()) {
    return;
  }

  if (!constraintsOk(state)) {
    return;
  }

  if (state.solved()) {
    printState("solved", state);
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

  State testState = initState \
    .setDigit(1, 1, digitFromSingleValue(8)) \
    .setDigit(2, 2, digitFromSingleValue(2));
  cout << "\nSolve\n";
  solve(testState);
}
