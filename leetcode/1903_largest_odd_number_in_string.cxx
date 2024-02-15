#include <iostream>
using namespace std;

class Solution {
 public:
  string largestOddNumber(string s) {
    int i = s.size() - 1;

    while (i >= 0) {
      int num = s[i] - '0';

      if (num % 2 == 1) break;
      i--;
    }
    return s.substr(0, i + 1);
  }
};