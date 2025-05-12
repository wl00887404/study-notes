#include <vector>
using namespace std;

/**
 * 輸入兩個陣列，值只有 0 跟正數
 * 0 要調整成其他的正數，想辦法讓兩個陣列總和一樣
 *
 * nums1 = [0, 0, 20], nums2 = [0, 10]
 * a + b + 20 = c + 10 => a + b - c = -10
 * 簡化成 x + 20 = y + 10, minX = 2, minY = 1
 *
 * x + 20 = 1 + 10 => x = -7
 * 2 + 20 = y + 10 => y = 12
 */

/**
 * 抽象化來看
 *
 * x + sum1 == y + sum2
 *
 * maybeX = minY + sum2 - sum1
 *   => maybeX >= minX
 *   => minY + sum2 - sum1 >= minX
 *   => minY + sum2 - (minX + sum1) >= 0
 * maybeY = minX + sum1 - sum2
 *   => maybeY >= minY
 *   => minX + sum1 - sum2 >= minY
 *   => minX + sum1 - (minY + sum2) >= 0
 *
 * [0, 4] + [0, 0, 3]
 * => 兩邊都是一樣 => [1, 4] + [1, 1, 3]
 *
 * [0, 5] + [0, 0, 3]
 * => minX + sum1 比較大 => [1, 5] + [2, 1, 3]
 *
 * [0, 4] + [0, 0, 4]
 * => minY + sum2 比較大 => [2, 4] + [1, 1, 4]
 */

/**
 * nums1 = [2, 0, 2, 0], nums2 = [1, 4]
 * minX = 2, sum1 = 4, minY = 0, sum2 = 5
 *
 * minX + sum1 比較大，但是 nums2 不能調整 => 無解
 */

/**
 * 重來重來，核心思路應該是：
 * nums1 全填 1 的最小值，與 nums2 全填 1 的最小值比較
 * 兩邊統一調整成比較大的那個
 */

class Solution {
 public:
  long long minSum(vector<int>& nums1, vector<int>& nums2) {
    int zeroCount1 = 0;
    long long sum1 = 0;
    int zeroCount2 = 0;
    long long sum2 = 0;

    for (const int& num : nums1) {
      if (num == 0) {
        zeroCount1++;
        sum1++;
      } else {
        sum1 += num;
      }
    }

    for (const int& num : nums2) {
      if (num == 0) {
        zeroCount2++;
        sum2++;
      } else {
        sum2 += num;
      }
    }

    // 都不能調整
    if (zeroCount1 == 0 && zeroCount2 == 0) {
      return sum1 == sum2 ? sum1 : -1;
    }

    if (zeroCount1 == 0) {
      return sum1 >= sum2 ? sum1 : -1;
    }

    if (zeroCount2 == 0) {
      return sum1 <= sum2 ? sum2 : -1;
    }

    return max(sum1, sum2);
  }
};