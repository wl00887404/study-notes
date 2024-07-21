#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * [0, 0, 0, 1, 0, 1, 0 ,1] 可以推出 [0, 0, 0, 1, 1, 2, 2, 3]
 * goal = 0， (0, 0) = 3 * 2 / 2 + 1 = 4, (1, 1) = 2 * 1 / 2 =
 */

class Solution {
 public:
  int numSubarraysWithSum(vector<int>& nums, int goal) {
    unordered_map<int, int> map;

    map[0] = 1;  // 補一個 0 在前面，適應不用相減的 subarray

    int sum = 0;
    for (const int& num : nums) {
      sum += num;
      if (!map.count(sum)) map[sum] = 0;
      map[sum]++;
    }

    int result = 0;
    int limit = sum - goal;

    for (int i = 0; i <= limit; i++) {
      int count1 = map.count(i) ? map[i] : 0;

      if (goal == 0) {
        result += count1 * (count1 - 1) / 2;
      } else {
        int count2 = map.count(i + goal) ? map[i + goal] : 0;
        result += count1 * count2;
      }
    }

    return result;
  }
};