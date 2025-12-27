namespace digit {

  #define MIN 1
  #define MAX 9
  #define ALL_OPTIONS 0b1111111110

  class Digit {
    const int data;

  public:
    Digit(): data{ALL_OPTIONS} {};
    Digit(int data_): data {data_} {};

    int countOptions() const;
    int getData() const;
    int getValue() const;
  };


  Digit digitFromSingleValue(int singleValue);

}
