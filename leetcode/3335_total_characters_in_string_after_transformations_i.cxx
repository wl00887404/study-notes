#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * 進行一次轉換： a => b, b => c, ..., z => ab
 * 問轉換 t 次後的字串長度
 *
 * 一個 vector(26, 0) 儲存個別的數量
 * next c = prev b
 * next z = prev x
 * next a = prev z
 * next b = prev z + prev a
 *
 * 關鍵在 z 會變成 ab ，要是 z 只會變成 a，字串長度就不會改變
 *
 * a T 1 = b
 * a T 2 = c
 * ...
 * a T 25 = z
 * a T 26 = ab
 * a T 27 = bc
 *
 * 某字元有 k 次，轉換 26 次
 * 他自己會回到原位，但下一位數會因為自己回到原位，產生了 k 個
 */

/**
 * 先把字元都 shift 成 a ？
 * 然後可以重複使用 a 的計算結果
 *
 * z => a T 25
 * y => a T 24
 * ...
 * b => a T 1
 * a => a
 *
 * s = "abcyy", t = 2
 * = a T 2 + b T 2 + c T 2 + 2 * y T 2
 * = a T 2 + a T 3 + a T 4 + 2 * a T 26
 * = a T 2 + a T 3 + a T 4 + 2 * (a T 0 + b T 0)
 * = 1 + 1 + 1 + 2 * (1 + 1) = 7
 *
 * s = "a", t = 52
 * = a T 52
 * = a T 26 + b T 26 = a T 26 + a T 27
 * = a T 0 + b T 0 + a T 1 + b T 1
 * = a T 0 + a T 1 + a T 1 + a T 2
 * = 4
 */

class Solution {
 public:
  static const int MOD = 1000000007;
  unordered_map<int, int> cache;

  int lengthAfterTransformations(string s, int t) {
    long long result = 0;

    for (const char& c : s) {
      result += helper(c - 'a' + t);
      result %= MOD;
    }

    return result;
  }

  // 當字元是 a，轉換 t 次
  int helper(int t) {
    if (t < 26) return 1;

    // 過 26 會產生 ab T (t - 26)
    // 也就是 (a + t - 26) + (a + t - 26 + 1)
    long long result = helperWithCache(t - 26);
    result += helperWithCache(t - 25);
    result %= MOD;

    return result;
  }

  int helperWithCache(int t) {
    if (t < 26) return 1;

    if (cache.count(t)) return cache[t];

    cache[t] = helper(t);
    return cache[t];
  }
};