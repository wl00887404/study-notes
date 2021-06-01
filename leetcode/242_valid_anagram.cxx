#include <iostream>
using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    int sLength = s.size();
    int tLength = t.size();
    if (sLength != tLength) return false;

    int frequencies[26];
    for (int i = 0; i < 26; i++) {
      frequencies[i] = 0;
    }

    for (int i = 0; i < sLength; i++) {
      frequencies[s[i] - 'a']++;
      frequencies[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
      if (frequencies[i] != 0) return false;
    }

    return true;
  }
} solution;

int main() { return 0; }