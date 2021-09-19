#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxTurbulenceSize(vector<int>& arr) {
    int size = arr.size();
    if (size == 1) return 1;

    int slope = getSign(arr[1] - arr[0]);

    int length = slope != 0 ? 2 : 1;
    int result = length;

    for (int i = 2; i < size; i++) {
      int nextSlope = getSign(arr[i] - arr[i - 1]);

      if (slope * nextSlope < 0) {
        length++;
      } else {
        length = nextSlope != 0 ? 2 : 1;
      }

      slope = nextSlope;

      result = max(result, length);
    }

    return result;
  }

  int getSign(int value) {
    if (value > 0) return 1;
    if (value < 0) return -1;

    return 0;
  }
} solution;

int main() {
  // vector<int> arr = {9, 4, 2, 10, 7, 8, 8, 1, 9};
  vector<int> arr = {9, 9};

  cout << solution.maxTurbulenceSize(arr) << endl;

  return 0;
}