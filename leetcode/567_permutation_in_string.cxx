#include <iostream>
using namespace std;

/**
 * 超慢
 */

class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    int length1 = s1.size();
    int length2 = s2.size();
    int charMap1[26] = {0};

    for (int i = 0; i < length1; i++) charMap1[s1[i] - 'a']++;

    int limit = length2 - length1 + 1;

    for (int i = 0; i < limit; i++) {
      int j = 0;
      int charMap2[26] = {0};

      while (true) {
        if (j >= length1) return true;

        int ci = s2[i + j] - 'a';

        if (charMap1[ci] == 0 || charMap2[ci] == charMap1[ci]) break;

        charMap2[ci]++;
        j++;
      }
    }

    return false;
  }
};