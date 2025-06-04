
#include <iostream>
using namespace std;

/**
 * 題目一次看不懂，就看第二次
 * 但是通常看第二次還是看不懂
 *
 * 要把 word 分成 numFriends 份，找到字典序最大的子字串
 *
 * 'abcd' 分成 1 份 => 整個字串長度 4
 *        分成 2 份 => 1 個字元 + 長度 3
 *        分成 3 份 => 2 個字元 + 長度 2
 *
 * 分成 n => 長度 - numFriends + 1
 * 字典序是比第一個字母 z > x > y > ... > a
 *
 * slide window + (word[i] - 'a') * 26，每次移動就是移除 (word[i] - 'a' ) * 26
 * 只是那個數字超級大的，字串長度最多到 5000
 *
 * 欸不對，突然發現這題也是字尾樹嘛
 */

/**
 * 抓到一個不是分成「長度 - numFriends + 1」的結果
 * word = "aann", numFriends = 2
 * 最佳結果是 nn
 */

class Solution {
 public:
  string* wordP;
  int size;
  int maxSubstringSize;
  static constexpr char lessThanA = ('a' - 1);
  string answerString(string word, int numFriends) {
    if (numFriends == 1) return word;  // 只有一個朋友時，無法分區

    wordP = &word;
    size = word.size();
    maxSubstringSize = word.size() - numFriends + 1;
    int result = 0;

    for (int i = 1; i < word.size(); i++) {
      if (compare(result, i) <= 0) continue;

      result = i;
    }

    return word.substr(result, min(maxSubstringSize, size - result));
  }

  // -1 => i 比較小
  // 1 => i 比較大
  // 0 => 一樣大
  int compare(int i, int j) {
    string& word = *wordP;

    for (int k = 0; k < maxSubstringSize; k++) {
      const char& c1 = i + k < size ? word[i + k] : lessThanA;
      const char& c2 = j + k < size ? word[j + k] : lessThanA;

      if (c1 == c2) continue;

      return c1 > c2 ? -1 : 1;
    }

    return 0;
  }
};