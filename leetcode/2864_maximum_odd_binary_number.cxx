#include <iostream>

using namespace std;

class Solution {
 public:
  string maximumOddBinaryNumber(string s) {
    int size = s.size();
    char result[size + 1];
    result[size - 1] = '1';
    result[size] = '\0';

    int count = -1;  // 最後的 1 不用算
    for (const char& c : s) {
      if (c == '1') count++;
    }

    for (int i = 0; i < size - 1; i++) {
      if (i < count) {
        result[i] = '1';
      } else {
        result[i] = '0';
      }
    }

    return string(result);
  }
};