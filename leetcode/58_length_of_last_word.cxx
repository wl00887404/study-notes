#include <iostream>

#include "./TreeNode.cxx"
using namespace std;

class Solution {
 public:
  int lengthOfLastWord(string s) {
    int last = s.size() - 1;

    while (last >= 0 && s[last] == ' ') last--;
    int result = 0;

    while (last >= 0 && s[last] != ' ') {
      last--;
      result++;
    }

    return result;
  }
};