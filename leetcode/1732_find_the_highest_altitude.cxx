#include <vector>
using namespace std;

class Solution {
 public:
  int largestAltitude(vector<int>& gain) {
    int sum = 0;
    int result = 0;

    for (int& x : gain) {
      sum += x;
      if (sum > result) result = sum;
    }

    return result;
  }
};