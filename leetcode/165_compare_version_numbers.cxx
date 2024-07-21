#include <iostream>

using namespace std;

class Solution {
 public:
  int compareVersion(const string& version1, const string& version2) {
    int length1 = version1.length();
    int length2 = version2.length();
    int i = 0;
    int j = 0;

    while (i < length1 || j < length2) {
      int value1 = 0;
      int value2 = 0;

      while (i < length1 && version1[i] != '.') {
        value1 *= 10;
        value1 += version1[i] - '0';
        i++;
      }
      while (j < length2 && version2[j] != '.') {
        value2 *= 10;
        value2 += version2[j] - '0';
        j++;
      }

      if (value1 < value2) return -1;
      if (value1 > value2) return 1;
      i++;
      j++;
    }

    return 0;
  }
};