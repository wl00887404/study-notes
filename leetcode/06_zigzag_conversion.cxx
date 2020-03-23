#include <iostream>
#include <vector>

using namespace std;

/**
 * 輸入 PAYPALISHIRING
 * 回傳 PAHNAPLSIIGYIR
 *
 * 先往下在斜上去
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
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
 * 1 51  5
 * 24 2 4
 * 3  3
 */

class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;

    vector<string> rows(numRows);

    for (int i = 0; i < numRows; i++) rows.push_back("");

    int length = s.length();
    int triangleLength = numRows * 2 - 2;

    for (int i = 0; i < length; i++) {
      int triangleIndex = i % triangleLength;
      int rowIndex = triangleIndex < numRows ? triangleIndex
                                             : triangleLength - triangleIndex;
      rows[rowIndex] += s[i];
    }

    string result = "";
    for (int i = 0; i < numRows; i++) result += rows[i];

    return result;
  }
} solution;

int main() {
  // cout << solution.convert("PAYPALISHIRING", 3) << endl;

  cout << solution.convert("PAYPALISHIRING", 4) << endl;

  return 0;
}