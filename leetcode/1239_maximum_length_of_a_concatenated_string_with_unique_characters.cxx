#include <math.h>

#include <iostream>
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
 * TODO: 看一下 DP 解
 * 為什麼它比我快啦
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

    for (int i = 0; i < size; i++) {
      values[i] = 0;
      lengths[i] = strings[i].size();
      for (char& c : strings[i]) {
        int& bit = bits[c - 'a'];
        // 自己沒有重複自己
        if ((values[i] & bit) == 0) {
          values[i] |= bit;
        } else {
          values[i] = 0;
          break;
        }
      }
    }

    // 第 i 位的 bit 值對應的結果
    unordered_map<int, int> cache[size];

    return helper(size, values, lengths, cache, 0, 0);
  }

  int helper(int& size, int* values, int* lengths,
             unordered_map<int, int>* cache, int i, int value) {
    if (i == size) return 0;
    // 一樣分為選的結果與不選的結果
    if (cache[i].count(value)) return cache[i][value];

    cache[i][value] = 0;
    // 如果兩者字串沒有重疊可以選
    if (values[i] != 0 && (value & values[i]) == 0) {
      cache[i][value] =
          max(cache[i][value], lengths[i] + helper(size, values, lengths, cache,
                                                   i + 1, value | values[i]));
    }

    cache[i][value] = max(cache[i][value],
                          helper(size, values, lengths, cache, i + 1, value));

    return cache[i][value];
  }
} solution;

int main() {
  vector<string> arr = {"uu"};

  cout << solution.maxLength(arr) << endl;

  return 0;
}