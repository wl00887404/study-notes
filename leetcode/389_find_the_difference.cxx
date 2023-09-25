#include <iostream>

using namespace std;

/**
 * 2023/9/25 的每日
 * 原來我以前寫過喔
 */
class Solution2022 {
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

class Solution {
 public:
  char findTheDifference(string s, string t) {
    int sSize = s.size();
    int result = 0;
    int i;

    for (i = 0; i < sSize; i++) {
      result += t[i];
      result -= s[i];
    }

    result += t[i];

    return (char)result;
  }
};