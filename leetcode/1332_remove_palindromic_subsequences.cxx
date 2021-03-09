#include <iostream>
using namespace std;

/**
 * 這題只有 a 、 b
 * if(空字串) return 0
 * if(回文字串) return 1
 *
 * return 2 // 把 a 、 b 都移除掉
 */
class Solution {
 public:
  int removePalindromeSub(string s) {
    int length = s.length();

    if (length == 0) return 0;

    for (int i = length / 2; i >= 0; i--) {
      if (s[i] != s[length - i - 1]) return 2;
    }

    return 1;
  }
};