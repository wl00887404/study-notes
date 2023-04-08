#include <math.h>

#include <iostream>
#include <vector>

using namespace std;

/**
 * gray code 序列
 * 每一碼只能相差一個 bit
 *
 * n = 1 => 0, 1
 * n = 2 => 00, 01, 11, 10
 *          看來是 n = 1 開場，補上 2 ** 1 再 n = 1 倒轉
 * n = 3 => 000, 001, 011, 010, 110 , 111, 101, 100
 *          一樣是 n = 2 開場，補上 2 ** 2 再 n = 1 倒轉
 */

class Solution {
 public:
  vector<int> grayCode(int n) {
    vector<int> result = {0, 1};

    for (int i = 2; i <= n; i++) {
      int leading = pow(2, i - 1);
      for (int last = result.size() - 1; last >= 0; last--) {
        result.push_back(leading + result[last]);
      }
    }

    return result;
  }
};