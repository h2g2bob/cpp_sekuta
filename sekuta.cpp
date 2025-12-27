#include <iostream>

using namespace std;

#define MIN 1
#define MAX 9
#define ALL_OPTIONS 0b1111111110

class Digit {
  const int data;

public:
  Digit(): data{ALL_OPTIONS} {};
  Digit(int data_): data {data_} {};

  int countOptions() const {
    int options = 0;
    for (int temp = data; temp; temp = temp >> 1) {
      if (temp & 0x1) {
        options ++;
      }
    }
    return options;
  }

  int getData() const {
    return data;
  }

  int getValue() const {
    for (int i = MIN; i <= MAX; i++) {
      if (data == 1 << i) {
        return i;
      }
    }
    return 0;
  }
};


Digit digitFromSingleValue(int singleValue){
  return Digit {1 << singleValue};
}

// class State {
//  a, b, c, d, e, f, g, h, i: int


int main(int argc, char *argv[]) {
  cout << "Hello world\n";

  const Digit digA = digitFromSingleValue(3);
  cout << "DigitA " << digA.getData() << " (" << digA.getValue() << ") has " << digA.countOptions() << " options\n";

  const Digit digB {};
  cout << "DigitB " << digB.getData() << " (" << digB.getValue() << ") has " << digB.countOptions() << " options\n";
}
