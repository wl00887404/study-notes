#include <iostream>
#include <vector>
using namespace std;

/**
 * 這題分佈很奇怪
 * 明顯比較快的答案
 * 實際上跑分會落在超後面
 */

class Solution {
 public:
  string shiftingLetters(string s, vector<int>& shifts) {
    int length = s.length();

    char result[length + 1];
    result[length] = '\0';
    int sumShifts = 0;

    int& i = length;
    while (i--) {
      sumShifts = (sumShifts + shifts[i]) % 26;

      result[i] = 'a' + (s[i] - 'a' + sumShifts) % 26;
    }

    return string(result);
  }
};