#include <vector>

using namespace std;

class Solution {
 public:
  vector<int>* flowerbedPointer;
  int size;

  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (n == 0) return true;
    flowerbedPointer = &flowerbed;
    size = flowerbed.size();

    for (int i = 0; i < size; i++) {
      if (get(i) == 0 && get(i - 1) == 0 && get(i + 1) == 0) {
        n--;
        flowerbed[i] = 1;
      }
      if (n == 0) return true;
    }

    return false;
  }
  int get(int i) {
    vector<int>& flowerbed = *flowerbedPointer;

    if (i < 0) return 0;
    if (i >= size) return 0;

    return flowerbed[i];
  }
};