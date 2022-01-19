#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * pattern 一個字元表示一個字
 * 而且關係是一對一
 * 不能有一對多或多對一
 */

class Solution {
 public:
  bool wordPattern(string pattern, string s) {
    unordered_map<char, string> map;
    unordered_set<string> set;
    int pSize = pattern.size();
    int sSize = s.size();
    int i = 0;
    int j = 0;

    while (i < pSize && j < sSize) {
      int length = 0;
      while (j + length < sSize && s[j + length] != ' ') length++;

      string substr = s.substr(j, length);

      if (map.count(pattern[i]) && map[pattern[i]] != substr) return false;

      // 這個 substr 已經有代號了
      if (set.count(substr)) return false;

      map[pattern[i]] = substr;
      set.insert(substr);

      i++;
      j += length + 1;
    }

    return i >= pSize && j >= sSize;
  }
};