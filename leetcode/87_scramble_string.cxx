#include <iostream>
#include <vector>

using namespace std;

/**
 * scramble 是決定一個斷點，然後前後交換字串
 * 然後可以再對前字串、後字串，分別操作
 * 問不斷交換，有沒有機會從 s1 變成 s2
 *
 * 感覺不是暴力解的出來的耶
 * great 會有 8 種結果（字串長度 - 1 後 / 2 ）
 * [g/reat, reat/g,]
 * [gr/eat, eat/gr]
 * [gre/at, at/gre]
 * [grea/t, t/grea]
 */

/**
 * 蝦 dp 一潑
 * TODO: 弄清楚在幹嘛
 */
class Solution {
 public:
  bool isScramble(string s1, string s2) {
    length = s1.length();
    s1Pointer = &s1;
    s2Pointer = &s2;
    cache.resize(810000, -1); // 這個 size 是隨便寫的

    return helper(0, length, 0);
  }
  int length;
  string* s1Pointer;
  string* s2Pointer;
  vector<int> cache;

  int getKey(int begin, int end, int to) {
    return begin * length * length + end * length + to;
  }
  // begin: s1 的 substring 的開頭
  // end: s1 的 substring 的開頭
  // to: 對應 s2 的位置
  bool helper(int begin, int end, int to) {
    int key = getKey(begin, end, to);
    if (cache[key] != -1) return cache[key];

    string& s1 = *s1Pointer;
    string& s2 = *s2Pointer;

    if (end - begin == 1) {
      cache[key] = s1[begin] == s2[to];
      return cache[key];
    }

    vector<int> alphabets(26, 0);
    for (int i = 0; i < end - begin; i++) {
      int incIndex = s1[begin + i] - 'a';
      int decIndex = s2[to + i] - 'a';
      alphabets[incIndex]++;
      alphabets[decIndex]--;
    }

    for (int i = 0; i < 26; i++) {
      if (alphabets[i] != 0) {
        cache[key] = false;
        return cache[key];
      }
    }

    for (int i = begin + 1; i < end; i++) {
      // 前半是 begin, i
      // 後半是 i, end

      bool noSwapResult =
          helper(begin, i, to) && helper(i, end, to + i - begin);

      bool swapResult = helper(i, end, to) && helper(begin, i, to + end - i);

      if (noSwapResult || swapResult) return true;
    }

    cache[key] = false;
    return cache[key];
  }
} solution;