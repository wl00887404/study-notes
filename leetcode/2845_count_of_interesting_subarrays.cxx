#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 給一個陣列，回傳子陣列數量，該子陣列符合以下條件
 * const test = (subarray: number[]) => {
 *   if(subarray.length === 0) return false;
 *
 *   const count = subarray.filter(x => x % module === k)
 *   return count % module === k
 * }
 */

/**
 * nums = [4, 2, 10, 7], modulo = 3, k = 1
 *
 * targetCounts = [1, 1, 2, 3]
 * 1 => targetCounts[i] % 3 == 1 => [0] [1]
 * 2 => (targetCounts[i] - targetCounts[j]) % 3 === 1 => [0, 2] [1, 2] [2, 3]
 *
 * 1 的情境，本身是 3n + 1
 * 2 的情境，比較複雜
 *   3n + 0 可以配 3n - 1 => 3n + 2
 *   3n + 1 可以配 3n + 0
 *   3n + 2 可以配 3n + 1
 *
 *
 * reminderCounts = [1, 2, 1]
 *   3n + 0 有 1 個
 *   3n + 1 有 2 個
 *   3n + 2 有 1 個
 */

class Solution {
 public:
  long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
    int size = nums.size();

    unordered_map<int, int> reminderCountMap;
    long long result = 0;
    int targetCount = 0;

    for (int i = 0; i < size; i++) {
      const int& num = nums[i];
      if (num % modulo == k) {
        targetCount++;
      }

      if (targetCount % modulo == k) {
        result++;
      }

      int matchedReminder = mod(targetCount - k, modulo);

      if (reminderCountMap.count(matchedReminder)) {
        result += reminderCountMap[matchedReminder];
      }

      reminderCountMap[targetCount % modulo]++;
    }

    return result;
  }

  int mod(int x, int& modulo) {
    if (x < 0) x += modulo;

    return x % modulo;
  }
};