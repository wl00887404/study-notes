#include <iostream>
using namespace std;

/**
 * 輸入 PAYPALISHIRING
 * 回傳 PAHNAPLSIIGYIR
 *
 * 先往下在斜上去
 *
 * P A H N
 * APLSIIG
 * Y I R
 *
 * 如果 numRows 為 3 => 可以看 4 個字元型成一個三角形 => 00 1313 22
 *
 * 0 0
 * 1313
 * 2 2
 *
 * P  I  N
 * A LS IG
 * YA HR
 * P  I
 *
 * numRows 為 4 => 6 => 001515242433
 *
 * 0  0   0
 * 1 51  51
 * 24 2 4
 * 3  3
 */

class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;

    int length = s.length();

    char result[length + 1];
    result[length] = '\0';

    int triangleLength = numRows * 2 - 2;
    int k = 0;

    for (int i = 0; i < length; i += triangleLength) {
      result[k++] = s[i];
    }

    for (int i = 1; i < numRows - 1; i++) {
      int next = triangleLength - i * 2;

      for (int j = i; j < length; j += triangleLength) {
        result[k++] = s[j];

        if (j + next < length) {
          result[k++] = s[j + next];
        }
      }
    }

    for (int i = numRows - 1; i < length; i += triangleLength) {
      result[k++] = s[i];
    }

    return result;
  }
} solution;

int main() {
  cout << solution.convert("PAYPALISHIRING", 3) << endl;
  cout << "PAHNAPLSIIGYIR" << endl;

  // cout << solution.convert("PAYPALISHIRING", 4) << endl;
  // cout << "PINALSIGYAHRPI" << endl;

  return 0;
}