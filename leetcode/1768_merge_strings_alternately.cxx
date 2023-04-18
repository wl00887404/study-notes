#include <iostream>

using namespace std;

class Solution {
 public:
  string mergeAlternately(string word1, string word2) {
    int size1 = word1.size();
    int size2 = word2.size();

    char cs[size1 + size2 + 1];
    cs[size1 + size2] = '\0';

    int minSize = min(size1, size2);
    for (int i = 0; i < minSize; i++) {
      cs[i * 2] = word1[i];
      cs[i *2 +1] = word2[i];
    }

    int& j = minSize;
    while (j < size1) {
      cs[j + size2] = word1[j];
      j++;
    }

    while (j < size2) {
      cs[j + size1] = word2[j];
      j++;
    }

    return string(cs);
  }
};