#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * ~~找第一個數字最大的~~
 * 依序排在一起就好
 *
 * 不能找第一個數字最大的
 * 因為數字一樣的情況不好處理
 * 像是 432 與 43243
 * 可以組成 43243243 或 43243432
 * 43243432 是大於 43243243 的
 *      ^              ^
 * 直接組合在一起比較最簡單
 */

class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    vector<string> strings;

    for (int& num : nums) {
      strings.push_back(to_string(num));
    }

    sort(strings.begin(), strings.end(), comparator);

    string result = "";
    for (string& s : strings) {
      if (result.size() == 0 && s == "0") continue;
      result += s;
    }

    if (result.size() == 0) return "0";

    return result;
  }

  static char getChar(string& s1, string& s2, int& size1, int& size2, int& i) {
    if (i < size1) return s1[i];

    return s2[i - size1];
  }

  static bool comparator(string& s1, string& s2) {
    int size1 = s1.size();
    int size2 = s2.size();

    for (int i = 0; i < size1 + size2; i++) {
      char c1 = getChar(s1, s2, size1, size2, i);
      char c2 = getChar(s2, s1, size2, size1, i);

      if (c1 == c2) continue;
      if (c1 > c2) return true;

      return false;
    }

    return false;
  }
};