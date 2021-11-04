#include <math.h>

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 重新確認題目
 * 每個字只會出現一次
 * 所以最大的長度就是 26
 *
 * 問題在要怎麼組合字串們
 * 題目求最長，所以貪婪會比較快
 *
 * -0, -1, -2, ...
 * 用前面的結果推測後面的結果
 *
 * -1 = -0 拿掉其中一個
 * -2 = -1 再拿掉一個
 *
 * 這樣的話用質數 hash 的方式還管用嗎？
 * 有沒有辦法直接從數值判斷是否有重複字元
 */

/**
 * 不用質數
 * 直接用一個 int 做 bitset 就好
 */

/**
 * 欸原來這題不是 hard 喔
 */

/**
 * 不是 pick 越多 element 就是最佳解
 *
 * 假設 strings = ["abc", "d", "e", "defgh", "ijk"]
 *
 * pick = 4, abc|d|e|ijk , length = 8
 * pick = 3, abc|defgh|ijk, length = 12
 */

/**
 * 寫法是一樣的
 * 不用 unordered_map 紀錄 cache 速度反而比較快
 * cache 處理不定值效能太差了嗎？
 */

class Solution {
 public:
  int maxLength(vector<string>& strings) {
    int size = strings.size();

    int bits[26];
    bits[0] = 1;
    for (int i = 1; i < 26; i++) {
      bits[i] = bits[i - 1] << 1;
    }

    // 預備每一個字串的 bit 值
    int values[size];
    int lengths[size];

    // 新的開頭，前面都放淘汰值
    int i = 0;
    for (int j = 0; j < size; j++) {
      values[j] = 0;
      lengths[j] = strings[j].size();
      for (char& c : strings[j]) {
        int& bit = bits[c - 'a'];
        // 遇到自己重複自己
        if ((values[j] & bit) != 0) {
          values[j] = values[i];
          lengths[j] = lengths[i];
          i++;
          break;
        }

        values[j] |= bit;
      }
    }

    int result = 0;
    helper(result, size, values, i, 0);

    return result;
  }

  int countBits(int n) {
    int result = 0;
    while (n) {
      if (n & 1) result++;
      n = n >> 1;
    }
    return result;
  }

  void helper(int& result, int& size, int* values, int i, int value) {
    // 一樣分為選的結果與不選的結果
    if (i == size) {
      result = max(result, countBits(value));
      return;
    }

    // 如果兩者字串沒有重疊可以選
    if ((value & values[i]) == 0) {
      helper(result, size, values, i + 1, value | values[i]);
    }

    helper(result, size, values, i + 1, value);
  }
} solution;

int main() {
  vector<string> arr = {"uu"};

  cout << solution.maxLength(arr) << endl;

  return 0;
}