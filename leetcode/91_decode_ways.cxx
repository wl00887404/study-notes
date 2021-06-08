#include <iostream>
using namespace std;

/**
 * 會重疊的可能
 * 11 ~ 19
 * 21 ~ 26
 * 27 不會重疊
 *
 * 223 => 2 2 3 | 2 23 | 22 3
 *   starts from 2 | starts from 22
 *
 * 229 => 2 2 9 | 22 9
 *   2 29 死去
 *
 * 0 最麻煩
 * 只有 10 20 不然就 invalid 了
 */

/**
 * 一步一步來
 * 2 => 1 (B)
 * 22 => 2 (BB, V)
 * 222 => 3 (BBB, BV, VB)
 * 2222 => 4 (BBBB, BVB, BBV, VBB)
 *
 * 2 => 1 (B)
 * 26 => 2 (BF, Z)
 * 262 => 2 (BFB, ZB)
 * 2626 => 3 (BFBF, ZBF, BFZ, ZZ)
 *
 * next possible 不是至少是 1
 * 有可能到 0
 * 如果是 11~19 22~26 才會是 2
 */

class Solution {
 public:
  int numDecodings(string s) {
    int length = s.length();
    int cache[length + 1];
    for (int i = 0; i < length + 1; i++) cache[i] = -1;

    return withCache(cache, s, 0, length);
  }

 private:
  int numDecodings(int* cache, string& s, int i, int& length) {
    if (i == length) return 1;
    if (s[i] == '0') return 0;
    // 3 ~ 9
    if (s[i] != '1' && s[i] != '2') {
      return withCache(cache, s, i + 1, length);
    }
    // 1, 2
    if (i + 1 == length) return 1;
    // 27 ~ 29
    if (s[i] == '2') {
      if (s[i + 1] == '7' || s[i + 1] == '8' || s[i + 1] == '9') {
        return withCache(cache, s, i + 1, length);
      }
    }
    // 10, 20
    if (s[i + 1] == '0') return withCache(cache, s, i + 2, length);

    return withCache(cache, s, i + 1, length) +
           withCache(cache, s, i + 2, length);
  }

  int withCache(int* cache, string& s, int i, int& length) {
    if (cache[i] != -1) return cache[i];

    int result = numDecodings(cache, s, i, length);
    cache[i] = result;

    return result;
  }
} solution;

int main() {
  cout << solution.numDecodings("12") << endl;
  return 0;
}