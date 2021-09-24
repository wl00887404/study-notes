#include <iostream>
using namespace std;

/**
 * 欸不是，不要把答案直接放在 hint 好不好
 */

class Solution {
 public:
  string breakPalindrome(string palindrome) {
    int length = palindrome.length();
    if (length == 1) return "";

    char cs[length + 1];
    cs[length] = '\0';

    int i = 0;
    bool hasModifyNotAChar = false;
    for (; i < length / 2; i++) {
      if (!hasModifyNotAChar && palindrome[i] != 'a') {
        cs[i] = 'a';
        hasModifyNotAChar = true;
      } else {
        cs[i] = palindrome[i];
      }
    }

    for (; i < length; i++) cs[i] = palindrome[i];

    if (!hasModifyNotAChar) cs[length - 1] = 'b';

    return string(cs);
  }
};