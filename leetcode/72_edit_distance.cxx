#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 改寫 1035？
 * 一樣的字符可以連線
 * 造成左右區塊
 *
 * 每個區塊長度相減全部加起來
 * 最小的就是答案
 */

/**
 * 過了是過了
 * 不過只有 5%
 * 有夠慢的
 *
 * 幹看了討論串答案
 * 可以 O(n) 喔
 * 太屌了吧
 *
 * TODO: 研究討論串答案
 * 還可以改成 one vector
 * 太過分了吧
 * https://leetcode.com/problems/edit-distance/discuss/25846/C%2B%2B-O(n)-space-DP
 */


/**
 * 2023/4/28 在 839 遇到類似的題目
 * 72 這題又稱為萊文斯坦距離 Levenshtein distance
*/
class Solution {
 public:
  int minDistance(string word1, string word2) {
    this->word1 = &word1;
    size1 = word1.size();
    size2 = word2.size();

    if (size1 == 0 || size2 == 0) return max(size1, size2);

    int array[size1 * size2];
    cache = array;

    for (int i = size1 * size2 - 1; 0 <= i; i--) array[i] = -1;

    for (int j = 0; j < size2; j++) {
      positionsByWord2[word2[j]].push_back(j);
    }

    return helper(0, 0);
  }

 private:
  string* word1;
  string* word2;
  int size1;
  int size2;
  int* cache;
  unordered_map<char, vector<int>> positionsByWord2;

  int helper(int i, int j) {
    /**
     * a b c
     * d d d a
     *
     * word1[0] word2[3] 連線
     * 下一個執行 helper(1, 4)
     * b c 要修改兩個字母
     * 要回傳 size1 - i + size2 - j
     */

    if (i >= size1 || j >= size2) {
      return size1 - i + size2 - j;
    }

    int cacheIndex = i * size2 + j;

    if (cache[cacheIndex] != -1) return cache[cacheIndex];

    int result = max(size1 - i, size2 - j);
    for (int k = i; k < size1; k++) {
      char& char1 = (*word1)[k];

      // 找到位置 i 下一個能匹配的 j
      if (!positionsByWord2.count(char1)) continue;

      for (int& nextJ : positionsByWord2[char1]) {
        if (nextJ < j) continue;

        // cout << k << " : " << nextJ << endl;
        // cout << "要修改的字數 = " << max(k - i, nextJ - j) << endl;
        int maybeNextResult = max(k - i, nextJ - j) + helper(k + 1, nextJ + 1);

        // cout << "選了 " << k << " : " << nextJ << " 的結果 " <<
        // maybeNextResult
        //      << endl;
        result = min(result, maybeNextResult);
      }
    }

    cache[cacheIndex] = result;

    // cout << "cache[" << i << "][" << j << "] = " << result << endl;

    return cache[cacheIndex];
  }
} solution;

int main() {
  cout << solution.minDistance("teacher", "apache") << endl;
  return 0;
}