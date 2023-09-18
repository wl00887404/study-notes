#include <iostream>

using namespace std;

class ParkingSystem {
 public:
  ParkingSystem(int big, int medium, int small) {
    this->big = big;
    this->medium = medium;
    this->small = small;
  }

  bool addCar(int carType) {
    if (carType == 1) {
      bool result = big > 0;
      if (big > 0) big--;
      return result;
    }

    if (carType == 2) {
      bool result = medium > 0;
      if (medium > 0) medium--;
      return result;
    }

    bool result = small > 0;
    if (small > 0) small--;
    return result;
  }

  int big;
  int medium;
  int small;
};
