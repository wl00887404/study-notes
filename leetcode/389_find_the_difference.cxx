#include <iostream>

using namespace std;

class Solution {
 public:
  char findTheDifference(string s, string t) {
    int frequencies[26];

    for (int i = 0; i < 26; i++) frequencies[i] = 0;

    for (char& c : s) frequencies[c - 'a']++;
    for (char& c : t) frequencies[c - 'a']--;

    int i = 0;
    while (frequencies[i] == 0) i++;

    return 'a' + i;
  }
};