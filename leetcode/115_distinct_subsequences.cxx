#include <iostream>
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
 * TODO: 研究一下吧
 */

/**
 * 範圍還是可以縮減
 * 直接嘗試從後面比對
 * 就可以知道最後一組的位置！
 *
 * 這個作法成功壓到 4ms ！
 * 超開心！
 */

class Solution {
 public:
  int numDistinct(string s, string t) {
    vector<int> positionsByAlphabets[52];
    int sLength = s.size();
    int tLength = t.size();
    // t[i] 在 s 可能的範圍;
    int limits[tLength];

    int i = sLength - 1;
    int j = tLength - 1;
    while (true) {
      // 找到符合最後 t 的組合 了
      if (j == -1) break;
      // 找不到符合 t 的組合
      if (i == -1) return 0;
      // 兩者相符
      if (s[i] == t[j]) {
        limits[j] = i + 1;
        i--;
        j--;
        continue;
      }
      // 不相符
      i--;
    }

    for (int i = 0; i < sLength; i++) {
      vector<int>& positions = positionsByAlphabets[getIndex(s[i])];
      positions.push_back(i);
    }

    vector<int> cache[tLength];
    for (int j = 0; j < tLength; j++) {
      vector<int>& positions = positionsByAlphabets[getIndex(t[j])];

      cache[j].resize(positions.size(), -1);
    }

    return helper(cache, tLength, limits, positionsByAlphabets, t, -1, 0);
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
  int helper(vector<int>* cache, int& tLength, int* limits,
             vector<int>* positionsByAlphabets, string& t, int i, int j) {
    // 找到一種組合
    if (j == tLength) return 1;

    char& c = t[j];
    vector<int>& positions = positionsByAlphabets[getIndex(c)];
    int size = positions.size();
    int result = 0;

    int k = findGreaterThanIndex(positions, i);

    while (k < size && positions[k] < limits[j]) {
      // 從 position 找下一個字母的結果
      if (cache[j][k] == -1) {
        cache[j][k] = helper(cache, tLength, limits, positionsByAlphabets, t,
                             positions[k], j + 1);
      }

      result += cache[j][k];
      k++;
    }

    return result;
  }

  int findGreaterThanIndex(vector<int>& positions, int& i) {
    // 要找到第一個大於 i 的 index

    int left = 0;
    int right = positions.size();

    while (left < right) {
      int mid = (left + right) / 2;

      if (positions[mid] > i) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left;
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
