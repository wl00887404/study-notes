#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * 3335 來的，3335 的題目
 * 就是 nums = [1, 1, 1, ..., 2]，只有 z 會轉換成 ab
 * 3337 每個字元都可以設定轉換， a T 3 = bcd
 *
 * 原本的 helper 該有 index 嗎？
 * a 配 nums[i]，要是 nums[i] 是 3，轉換 1 次變成 bcd
 *
 * if(nums[i] == 1) return 1;
 * if(nums[i] == 2) return helper(i, t - 1) + helper(i + 1, t - 1) + helper(i, +
 * 2, t - 1)
 */

/**
 * TODO: 每日一題偷抄作業，下次補
 */

class StackOverflowSolution {
 public:
  static const int MOD = 1000000007;
  unordered_map<long long, int> cache;
  vector<int>* numsP;

  int lengthAfterTransformations(string s, int t, vector<int>& nums) {
    numsP = &nums;
    long long result = 0;

    for (const char& c : s) {
      result += helper(c - 'a', t);
      result %= MOD;
    }

    return result;
  }

  int helper(int cIndex, int t) {
    if (t == 0) return 1;

    vector<int>& nums = *numsP;

    long long result = 0;
    for (int i = 1; i <= nums[cIndex]; i++) {
      result += helperWithCache((cIndex + i) % 26, t - 1);
      result %= MOD;
    }

    return result;
  }

  int helperWithCache(int cIndex, int t) {
    long long key = t;
    key = key * 26 + cIndex;

    if (cache.count(key)) return cache[key];

    cache[key] = helper(cIndex, t);
    return cache[key];
  }
};

// 反而 memory 爆開
class Solution {
 public:
  static const int MOD = 1000000007;

  int lengthAfterTransformations(string s, int t, vector<int>& nums) {
    // dp[t][s[] - 'a']
    vector<vector<int>> dp(t + 1, vector<int>(26, 0));

    for (int i = 0; i < 26; i++) {
      dp[0][i] = 1;  // 不轉換就是自己
    }

    for (int i = 1; i <= t; i++) {
      for (int j = 0; j < 26; j++) {
        long long result = 0;
        for (int k = 1; k <= nums[j]; k++) {
          result += dp[i - 1][(j + k) % 26];
        }
        dp[i][j] = result % MOD;
      }
    }

    long long result = 0;
    for (const char& c : s) {
      result += dp[t][c - 'a'];
      result %= MOD;
    }

    return result;
  }
};