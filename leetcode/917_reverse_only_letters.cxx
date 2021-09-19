#include <iostream>

using namespace std;

class Solution {
 public:
  string reverseOnlyLetters(string s) {
    int length = s.length();
    int left = 0;
    int right = length;

    char result[length + 1];
    result[length] = '\0';

    while (true) {
      while (left < right && !isAlphabet(s[left])) {
        result[left] = s[left];
        left++;
      }

      while (left < right && !isAlphabet(s[right - 1])) {
        result[right - 1] = s[right - 1];
        right--;
      }

      if (left >= right) break;

      result[right - 1] = s[left];
      result[left] = s[right - 1];

      left++;
      right--;
    }

    return string(result);
  }

  bool isAlphabet(char &c) {
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
  }
};