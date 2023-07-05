#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> getAverages(vector<int>& nums, int k) {
    int size = nums.size();
    vector<int> result(size, -1);

    if (size < 2 * k + 1) return result;

    long long sum = 0;
    for (int i = 0; i < 2 * k + 1; i++) {
      sum += nums[i];
    }

    result[k] = sum / (2 * k + 1);

    int i = 2 * k + 1;
    while (i < size) {
      sum += nums[i] - nums[i - 2 * k - 1];
      result[i - k] = sum / (2 * k + 1);
      i++;
    }

    return result;
  }
};