#include <iostream>
using namespace std;

/**
 * 跟 5_longest_palindromic_substring.cxx 相同
 */

class Solution {
 public:
  int countSubstrings(string s) {
    int length = s.length();
    int paddedLength = 2 * length + 3;
    char paddedS[paddedLength];
    int result = 0;
    paddedS[0] = '^';
    paddedS[paddedLength - 1] = '$';
    for (int i = 1; i < paddedLength - 1; i++) {
      if (i % 2 == 1) {
        paddedS[i] = '#';
      } else {
        paddedS[i] = s[i / 2 - 1];
      }
    }

    for (int i = 1; i < paddedLength - 1; i++) {
      int radius = 0;
      while (paddedS[i + radius + 1] == paddedS[i - radius - 1]) radius++;
      result += (radius + 1) / 2;
    }

    return result;
  }
};