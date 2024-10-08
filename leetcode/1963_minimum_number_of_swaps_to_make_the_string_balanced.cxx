#include <iostream>
using namespace std;

class Solution {
 public:
  int minSwaps(string s) {
    int size = s.size();
    int i = 0;
    int j = size - 1;
    int openingBracketCount = 0;
    int result = 0;

    for (; i < j; i++) {
      // 遇到 [ 記錄數量
      if (s[i] == '[') {
        openingBracketCount++;
        continue;
      }

      // 接下來都是 s[i] == ']' 的情境

      // 前面有 [ 可以匹配
      if (openingBracketCount > 0) {
        openingBracketCount--;
        continue;
      }

      // 沒有 [ 可以匹配了
      // 從後面找一個 [ 來交換
      while (s[j] != '[') j--;

      // 把 ] 換去了 tail，再來不用檢查 tail
      // 因為
      j--;

      openingBracketCount++;  // 把 [ 換來前面了，所以 count 可以 ++
      result++;
    }

    return result;
  }
};