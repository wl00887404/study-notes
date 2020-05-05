#include <iostream>
using namespace std;

class Solution {
 public:
  int firstUniqChar(string s) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int length = s.size();
    int frequencies[26] = {0};

    for (int i = 0; i < length; i++) frequencies[s[i] - 'a']++;

    for (int i = 0; i < length; i++) {
      if (frequencies[s[i] - 'a'] == 1) return i;
    }

    return -1;
  }
};