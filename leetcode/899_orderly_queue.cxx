#include <iostream>
using namespace std;

/**
 * 當 k 等於多少
 * 是可以直接 sort 的？
 * s=cba, k=1 不能 sort
 *
 * k 只要不是 1 都可以 sort
 * 等於有 1 個 buffer
 * 可以任一直動任何字元
 */

class Solution {
 public:
  string orderlyQueue(string s, int k) {
    int length = s.length();
    char result[length + 1];
    result[length] = '\0';

    if (k > 1) {
      // 如果 k < 1 表示有 buffer
      // 直接排序就可以了
      sort(result, s, length);
    } else {
      int smallestIndex = 0;

      for (int i = 1; i < length; i++) {
        int j = 0;
        // 比較字典順序
        while (j < length) {
          char c1 = s[(smallestIndex + j) % length];
          char c2 = s[(i + j) % length];
          if (c1 < c2) break;  // ab"c" 與 ab"d"
          if (c1 > c2) {
            // ab"d" 與 ab"c"
            smallestIndex = i;
            break;
          }
          // a"b"c 與 a"b"d
          j++;
        }

        i += j;
      }

      for (int i = 0; i < length; i++) {
        result[i] = s[(i + smallestIndex) % length];
      }
    }

    return string(result);
  }

  void sort(char* result, string& s, int& length) {
    // 因為內容物確定是 26 的字母
    // 直接線性 sort 即可
    int frequencies[26];

    for (int i = 0; i < 26; i++) frequencies[i] = 0;
    for (int i = 0; i < length; i++) frequencies[s[i] - 'a']++;
    int i = 0;
    for (int j = 0; j < length; j++) {
      while (frequencies[i] == 0) i++;

      result[j] = i + 'a';
      frequencies[i]--;
    }
  }
};
