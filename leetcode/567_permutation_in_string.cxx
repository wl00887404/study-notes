#include <iostream>
using namespace std;

class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    int length1 = s1.size();
    int length2 = s2.size();
    int charMap1[26] = {0};
    int charMap2[26] = {0};

    for (int i = 0; i < length1; i++) charMap1[s1[i] - 'a']++;

    int limit = length2 - length1 + 1;
    int i = 0;
    int j = 0;

    while (i < limit) {
      if (j >= length1) return true;

      int ci = s2[i + j] - 'a';

      if (charMap1[ci] == 0) {
        if (j < 26) {
          for (int k = 0; k < j; k++) charMap2[s2[i + k] - 'a']--;
        } else {
          for (int k = 0; k < 26; k++) charMap2[k] = 0;
        }

        i += j + 1;
        j = 0;

        continue;
      }

      if (charMap1[ci] == charMap2[ci]) {
        int k = 0;

        while (s2[i + k] != s2[i + j]) {
          charMap2[s2[i + k] - 'a']--;
          k++;
        }

        i += k + 1;
        j -= k;

        continue;
      }

      charMap2[ci]++;
      j++;
    }

    return false;
  }
} solution;

int main() {
  // cout << solution.checkInclusion("hello", "ooolleoooleh") << endl;
  cout << solution.checkInclusion("ab", "eidbaooo") << endl;

  return 0;
}