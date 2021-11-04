
#include <string.h>

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * 2021/9/19 這課是一定得逃的
 */

/**
 * 這題是傳入 s = "babgbag", t = "bag"
 * 其實就是正規表示式 b.*a.*g 可以 match 幾次
 *
 * b a b g b a g
 * 0 1 2 3 4 5 6
 *
 * 想用 suffix trie 解
 * b 出現的所有位置為 0 2 4
 *
 * 0 往後找 a
 *   a 出現的位置為 1 5
 *     1 往後找 g
 *       g 出現的位置為 3 6 => 2 個解
 *     5 往後找 g
 *       g 出現在的位置為 6 => 1 個解
 * 2 往後找 a
 *   a 出現的位置為 5
 *     5 往後找 g
 *       g 出現在的位置 6 => 1 個解
 * 4 往後找 a
 *   a 出現的位置為 5
 *     5 往後找 g
 *       g 出現在的位置 6 => 1 個解
 *
 * b 0 2 4
 * a 1   5 5 5
 * g 3 6 6 6 6
 *
 * s = "rabbbit", t = "rabbit"
 *
 * r a b b b i t
 * 0 1 2 3 4 5 6
 *
 * r 0
 * a 1
 * b 2 3 4
 * i 5
 * t 6
 *
 * r 0
 * a 1
 * b 2   3 4
 * b 3 4 4
 * i 5 5 5
 * t 6 6 6
 */

/**
 * 欸還可以這樣喔
 * 64 / 64 test cases passed, but took too long.
 */

/**
 * DP 解直接 0ms
 * 太兇狠了吧
 *
 * https://leetcode.com/problems/distinct-subsequences/discuss/37316/7-10-lines-C%2B%2B-Solutions-with-Detailed-Explanations-(O(m*n)-time-and-O(m)-space)
 */

class Solution {
 public:
  int numDistinct(string s, string t) {
    vector<int> positionsByAlphabets[52];
    int sLength = s.size();
    int tLength = t.size();

    for (int i = 0; i < sLength; i++) {
      positionsByAlphabets[getIndex(s[i])].push_back(i);
    }

    vector<int> cache[tLength];

    for (int i = 0; i < tLength; i++) {
      char& c = t[i];
      int positionsSize = positionsByAlphabets[getIndex(c)].size();

      // t 需要的必字元在 s 不存在
      if (positionsSize == 0) return 0;

      cache[i].resize(positionsSize, -1);
    }

    return helper(cache, sLength, tLength, positionsByAlphabets, t, -1, 0);
  }

  int getIndex(char& c) {
    if (c >= 'a') {
      return c - 'a' + 26;
    }

    return c - 'A';
  }

  /**
   * 如果是 s = "bbaag", t = "bag"
   * b 出現的所有位置為 0 1
   *
   * 0 往後找 a 的結果
   * 與 1 往後找 a 的結果一模一樣
   */

  // 從 i 開始比對 t[j] 的結果
  // cache[j][positionIndex] = 這個位置的結果
  int helper(vector<int>* cache, int& sLength, int& tLength,
             vector<int>* positionsByAlphabets, string& t, int i, int j) {
    // 剩餘字串不夠多了
    if (sLength - i < tLength - j) return 0;

    // 找到一種組合
    if (j == tLength) return 1;

    char& c = t[j];
    vector<int>& positions = positionsByAlphabets[getIndex(c)];
    int result = 0;
    int positionsSize = positions.size();
    for (int k = 0; k < positionsSize; k++) {
      int& position = positions[k];
      // 目前的位置不在 i 的後面
      if (position <= i) continue;
      if (i + tLength - i >= sLength) break;

      if (cache[j][k] == -1) {
        // 從 position 找下一個字母的結果
        cache[j][k] = helper(cache, sLength, tLength, positionsByAlphabets, t,
                             position, j + 1);
      }

      result += cache[j][k];
    }

    return result;
  }
} solution;

int main() {
  // string s =
  //     "adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeea"
  //     "ee"
  //     "abcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacddd"
  //     "c";

  // string t = "bcddceeeebecbc";

  string s = "rabbbit";
  string t = "rabbit";

  cout << solution.numDistinct(s, t) << endl;

  return 0;
}
