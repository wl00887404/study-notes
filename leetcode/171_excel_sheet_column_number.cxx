#include <iostream>

using namespace std;

/**
 * Excel 格子 26 進位
 * 沒什麼特別的
 */

class Solution {
 public:
  int titleToNumber(string columnTitle) {
    int result = 0;

    for (const char& c : columnTitle) {
      result = 26 * result + (c - 'A') + 1;
    }

    return result;
  }
};