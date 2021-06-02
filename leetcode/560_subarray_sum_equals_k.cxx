#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * #recommended:
 *   這題很棒耶
 *   輕鬆完成、困難優化、可以學到東西
 * 
 * brute force: 744 ms
 * 運用 (2, 4) = (0, 4) - (0 , 1) ： 316 ms
 * unordered_map.count: 44 ms 
 */

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int length = nums.size();
    int sums[length];
    int result = 0;
    int sum = 0;

    for (int i = 0; i < length; i++) {
      sum += nums[i];
      sums[i] = sum;

      if (nums[i] == k) result++;
      if (i != 0 && sum == k) result++;

      if (i < 2) continue;

      int j = i - 2;

      while (j >= 0) {
        if (sum - sums[j] == k) result++;

        j--;
      }
    }

    return result;
  }
};

class BestSolution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int length = nums.size();

    if (length == 0) return 0;

    // key = pervSums value = count.
    unordered_map<int, int> prevSums;
    int sum = 0;
    int count = 0;

    for (int i = 0; i < length; i++) {
      sum += nums[i];

      if (sum == k) count += 1;

      /**
       * 假設 s(2, 4) == k
       * 
       * s(2, 4) = s(0, 4) - s(0, 2)
       * k = sum - s(0, 2)
       * 
       * 反查有沒有 s(0, 2)
       */
      if (prevSums.count(sum - k)) {
        count += prevSums[sum - k];
      };

      prevSums[sum] += 1;
    }

    return count;
  }
};