#include <iostream>
#include <vector>
using namespace std;

/**
 * TODO: 每日一題偷抄作業，下次補
 */

/**
 * 分數計算的規則 = 子陣列的總和 * 子陣列的長度
 * 尋找分數小於 k 的子陣列數量
 *
 * 小陣列的分數一定比大陣列低
 * [1, 2, 3] = 6 * 3
 * [1, 2, 3, k] = (6 + k) * (3 + 1) = 6 * 3 +  3k + 6 + k = 6 * 3 + (4k + 6)
 * [2, 3] = (6 - k) * (3 - 1) = 6 * 3 - (2k - 6)
 *
 * sum 可以用 O(n ^ 2) 處理，往前減就可以取得 subarray 的 sum，長度也可以取得
 */

class TimeLimitExceededSolution {
 public:
  long long countSubarrays(vector<int>& nums, long long k) {
    vector<long long> sums;
    long long sum = 0;
    long long result = 0;
    int size = nums.size();
    bool hasGreaterThanK = false;
    int i = 0;

    for (; i < size; i++) {
      sum += nums[i];
      sums.push_back(sum);

      // 整個陣列分數無法滿足 k 了
      if (sum * (i + 1) < k) continue;

      // 分數終於夠了，計算先前的子陣列數量
      if (!hasGreaterThanK) {
        // nums = [2, 1, 4], k = 5
        // 4 的分數 > k， 加入 [2] [2, 1]
        result += (long long)(i) * (i + 1) / 2;
        hasGreaterThanK = true;
      }

      for (int j = 0; j < i; j++) {
        if ((sum - sums[j]) * (i - j) < k) {
          result += i - j;
          break;
        }
      }
    }

    // 整個陣列分數都沒達成 k
    if (!hasGreaterThanK) {
      result += (long long)(size) * (size + 1) / 2;
    }

    return result;
  }
};

/**
 * 當找到分數 < k 的子陣列之後，直接加總所有的子陣列很容易重複計算
 * nums = [100, 1, 2, 3], k = 50
 * sums = [100, 101, 102, 103]
 * sums[1] >= k => (sums[1] - sums[0]) < k => [1]
 * sums[2] >= k => (sums[2] - sums[0]) < k => [1] [2] [1, 2] => [1] 重複計算
 *
 * 想用類似 2444 的方式處理
 */
class Solution {
 public:
  long long countSubarrays(vector<int>& nums, long long k) {}
};