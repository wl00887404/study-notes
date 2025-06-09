#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * n = 111
 * 1, 10, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 11, 110, 111, 12
 *
 *    1
 *   10 => 優先補 0
 *  100 => 優先補 0
 * 1000 => 爆掉
 *  101 => / 10 + 1
 * 1010 => 爆掉
 *  102 => / 10 + 1
 * ...
 *  109
 * 1090 => 爆掉
 *   11 => / 10 +1
 *  110 => 優先補 0
 * 1100 => 爆掉
 *  111 => / 10 +1
 * 1110 => 爆掉
 *  112 => / 10 + 1，大於 111
 */
class Solution {
 public:
  vector<int> lexicalOrder(int n) {
    vector<int> result(n);

    int i = 0;
    int k = 1;

    while (i < n) {
      if (k <= n) {
        result[i] = k;
        i++;
      }

      // 進位時間
      if (k * 10 <= n) {
        // 可以補 0，優先補 0
        k *= 10;
        continue;
      }

      while (k % 10 == 9 || k + 1 > n) {
        // k 已經到 9 了，該退位 + 1 了
        // 或是 k + 1 已經比 n 還大了
        k /= 10;
      }
      k += 1;
    }

    return result;
  }
};