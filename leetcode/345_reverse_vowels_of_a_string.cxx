#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string reverseVowels(string s) {
    int size = s.size();
    char cs[size + 1];
    cs[size] = '\0';

    int left = 0;
    int right = size;

    while (left < right) {
      if (isVowel(s[left])) {
        while (left < right) {
          if (isVowel(s[right - 1])) break;

          cs[right - 1] = s[right - 1];
          right--;
        }

        cs[left] = s[right - 1];
        cs[right - 1] = s[left];
        left++;
        right--;
        continue;
      }

      cs[left] = s[left];
      left++;
    }

    return string(cs);
  }

  bool isVowel(char& c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
           c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
};