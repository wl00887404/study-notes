#include <iostream>
using namespace std;

/**
 * TODO: 每日一題偷抄作業，下次補
 */

/**
 * 跟 386 有關，本來想白嫖一題的
 * testcase 都超級大數，O(n) 會 TLE
 *
 * n = 783368691, k = 319151369
 *
 * 1, 10 ~ 19, 100 ~ 199, ... = 1 + 10 + 100 ...
 * 2, 20 ~ 29, 200 ~ 299,
 *
 * 99 = 1s * 11 + 2s * 11 ...
 * 100 = 1s * (11 + 1) + 2s * 11 ..
 * 200 = 1s * 111 + 2s * (11 + 1)
 *
 * 2 => 1
 * 20 => 1 + 10
 * 200 => 1 + 10 + 100
 * 有一樣的位數 1
 */

class Solution {
 public:
  int findKthNumber(int n, int k) {}

  int findKthNumber(int n, int k, int i = 0, long long j = 1) {
    int result;

    while (i < k) {
      if (j <= n) {
        result = j;
        i++;
      }

      // 進位時間
      if (j * 10 <= n) {
        // 可以補 0，優先補 0
        j *= 10;
        continue;
      }

      while (j % 10 == 9 || j + 1 > n) {
        // j 已經到 9 了，該退位 + 1 了
        // 或是 j + 1 已經比 n 還大了
        j /= 10;
      }
      j += 1;
    }

    return result;
  }
};