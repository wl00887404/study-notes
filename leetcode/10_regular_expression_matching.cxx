#include <iostream>
using namespace std;

/**
 * 這題要完全 match 耶
 * 只要針對 * 與 . 處理即可
 * 從後往前比較
 *
 * true 條件
 *   1. ^.*
 *   2. 同時 i == -1 && j ==-1
 * 字元不相符且非 . => false
 * 字元相符 => 迴圈繼續 => i == -1 && j == -1 => true
 */

/**
 * 換個邏輯
 * a* 開啟 a 數量無限
 * 比對下一個字元
 *   matched => clear 無限
 *   not matched => 有無限就過
 *
 * 多個無限怎麼處理？
 * push 進 stack 怎麼樣？
 */

class Solution {
 public:
  bool isMatch(string s, string p) {
    return isMatch(s, removeDuplicateStars(p), 0, 0);
  }
  
  string removeDuplicateStars(string p) {
    string nextP = "";
    int j = 0;
    int pLength = p.length();

    while (j < pLength) {
      if (j + 3 < pLength && p[j + 1] == '*' && p[j + 3] == '*' &&
          p[j] == p[j + 2]) {
        nextP += p[j];
        nextP += "*";
        char star = p[j];
        j += 4;

        while (p[j] == star && p[j + 1] == '*') j += 2;
      } else {
        nextP += p[j];
        j++;
      }
    }

    return nextP;
  }

  bool isMatch(string s, string p, int di, int dj) {
    int i = 0 + di;
    int j = 0 + dj;
    int sLength = s.length();
    int pLength = p.length();

    while (true) {
      if (j + 1 < pLength && p[j + 1] == '*') {
        int k = 0;

        while (i + k < sLength && (p[j] == s[i + k] || p[j] == '.')) {
          if (isMatch(s, p, i + k, j + 2)) return true;

          k++;
        }

        if (isMatch(s, p, i + k, j + 2)) return true;

        j += 2;
      } else {
        if (i == sLength && j == pLength) return true;
        if (i == sLength || j == pLength) return false;

        if (s[i] != p[j] && p[j] != '.') return false;

        i++;
        j++;
      }
    }
  }
} solution;

int main() {
  // cout << solution.isMatch("aa", "aa") << endl;
  // cout << solution.isMatch("aa", "a") << endl;
  // cout << solution.isMatch("aa", "b*a*") << endl;
  // cout << solution.isMatch("aab", "c*a*b") << endl;
  // cout << solution.isMatch("aaa", "ab*a*c*a") << endl;
  // cout << solution.isMatch("aaa", "a*a") << endl;
  // cout << solution.isMatch("", "c*c*") << endl;
  // cout << solution.isMatch("mississippi", "mis*is*p*.") << endl;
  // cout << solution.isMatch("mississippi", "mis*is*ip*.") << endl;

  return 0;
}