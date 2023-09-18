#include <math.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 2023/9/18
 * FIXME: 未完成
 */

/**
 * 序列中最小與最大
 * 先 sort 感覺會好處理很多
 * 這樣陣列頭尾就是最小與最大
 * 兩者和要一直維持在 target 中
 */

/**
 * [3, 3, 6, 8]
 * left = 3, right = 8 => sum = 11 > 10
 *   right --
 * left = 3, right = 6 => sum = 9 < 10
 *   中間的 3 可有可無， 所以 result += 2 ** 1
 *   之後產生兩條路， left++ || right-- ，有沒有可能產生相同的結果？
 *   不知道，先這樣好了
 */

/**
 * 兩兩一起做的演算法是對的
 * 只是速度太慢，而且遇到要 mod 1e9 + 7 的問題不知道怎麼解決
 * JavaScript 用 BigInt 可以撐到 test case 54/62
 */

class Solution {
 public:
  int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    unsigned long long result = 0;
    int size = nums.size();

    for (int left = 0; left < size; left++) {
      if (nums[left] * 2 > target) break;

      for (int right = left; right < size; right++) {
        // 頭尾相加爆開
        if (nums[left] + nums[right] > target) break;
        result += (unsigned long long)pow(2, max(0, (right - left - 1)));
        result %= 1000000007;
      }
    }

    return result;
  }
};