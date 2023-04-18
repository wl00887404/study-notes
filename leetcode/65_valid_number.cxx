#include <iostream>

using namespace std;

/**
 * 詳細看一下規則
 * 兩種版本，純小數或是科學記號
 * 純小數 [+-][0-9]+(\.[0-9]+)?
 * 科學記號就是純小數後面帶上 [eE]
 * 後面一定是接純整數
 */

class Solution {
 public:
  bool isNumber(string& s) {
    size = s.size();
    return isNumber(s, 0, false);
  }

  bool isNumber(string& s, int i, bool onlyInteger) {
    if (s[i] == 'e' || s[i] == 'E') return false;  // e 開場直接炸開
    
    if (s[i] == '+' || s[i] == '-') i++;
    if (i == size) return false;  // 只有正負號

    if (s[i] == 'e' || s[i] == 'E') return false;  // +e -e 開場再次炸開

    int nextI = passDigitals(s, i);
    int integerDigitCount = nextI - i;

    // [+-][0-9]+ ，是一個整數的朋友
    if (nextI == size) return integerDigitCount > 0;
    if (onlyInteger) return false;  // 後面還有接 . 或 e ，不是整數
    i = nextI;

    // 是一個小數的朋友
    if (s[i] == '.') {
      i++;
      nextI = passDigitals(s, i);
      if (integerDigitCount == 0 && nextI - i == 0) {
        return false;  // 單純的小數點
      }
      i = nextI;
    }

    if (s[i] == 'e' || s[i] == 'E') {
      return isNumber(s, i + 1, true);  // 是一個科學記號的朋友
    }

    return i == size;
  }

  int size;

  int passDigitals(string& s, int i) {
    while ('0' <= s[i] && s[i] <= '9' && i < size) {
      i++;
    }

    return i;
  }
};