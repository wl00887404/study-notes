#include <iostream>

using namespace std;

/**
 * A 映射 1，Z 映射 26，為了映射餘數，所以都 - 1
 * AA 映射 27 除以 26 是 1 ... 1 ，一樣都要 - 1 才能映射回 A
 */

class Solution {
 public:
  string convertToTitle(int columnNumber) {
    string result = "";

    while (true) {
      columnNumber--;
      result = (char)('A' + columnNumber % 26) + result;
      columnNumber /= 26;

      if (columnNumber == 0) break;
    }

    return result;
  }
};