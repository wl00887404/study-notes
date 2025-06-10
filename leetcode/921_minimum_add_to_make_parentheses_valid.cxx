#include <iostream>
using namespace std;

class Solution {
 public:
  int minAddToMakeValid(string s) {
    int result = 0;
    int openCount = 0;
    int size = s.size();

    for (int i = 0; i < size; i++) {
      if (s[i] == '(') {
        openCount++;
        continue;
      }

      // s[i] ==  ')'
      if (openCount > 0) {
        // is valid )
        openCount--;
        continue;
      }

      result++;
    }

    return result + openCount;
  }
};