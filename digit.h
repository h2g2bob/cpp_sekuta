namespace digit {

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


  Digit digitFromSingleValue(int singleValue);

}
