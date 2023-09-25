#include <iostream>

using namespace std;

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    int sSize = s.size();
    int i = 0;
    for (const char c : t) {
      if (i < sSize && s[i] == c) i++;
      if (i == sSize) break;
    }

    return i == sSize;
  }
};