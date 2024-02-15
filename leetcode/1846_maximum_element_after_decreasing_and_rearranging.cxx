#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    arr[0] = 1;
    int size = arr.size();
    for (int i = 1; i < size; i++) {
      if (arr[i] - arr[i - 1] <= 1) continue;
      // 絕對值超過 1 了
      arr[i] = arr[i - 1] + 1;
    }

    return arr[size - 1];
  }
};