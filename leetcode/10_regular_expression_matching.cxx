#include <iostream>
#include <queue>
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
  bool isMatch(string s, string p) { return isMatch(s, p, 0, 0); }
  bool isMatch(string s, string p, int di, int dj) {
    queue<char> stars;
    int i = 0 + di;
    int j = 0 + dj;
    int sLength = s.length();
    int pLength = p.length();

    while (true) {
      if (i == sLength && j == pLength) return true;
      if ((i == sLength || j == pLength) && stars.empty()) return false;

      while (pLength - 1 - j >= 1 && p[j + 1] == '*') {
        cout << p[j] << p[j + 1] << " push into stack" << endl;
        stars.push(p[j]);
        j += 2;
      }

      while (!stars.empty()) {

        if (stars.front() == '.') {
          if (j == pLength) return true;

          while (true) {
            if (i == sLength) return false;

            if (s[i] != p[j]) {
              i++;
              continue;
            }

            if (isMatch(s, p, i, j)) return true;
          }
        }
        
        if (j != pLength && s[i] == p[j]) {
          // abccc abc*d*c
          // abcdc abc*d*c
          while (!stars.empty() && stars.front() != p[j]) {
            stars.pop();
          }

          if (stars.empty()) continue;

          /**
           * 處理 a*(b*)a
           *
           * a*a 不是問題
           * a 已經 matched 了
           * a* 直接當 a* 處理
           *
           * 問題是 aa 與 aabba
           * aa aabba 單看開頭根本沒有差呀
           */

          while (s[i] == p[j]) i++;

          stars.pop();
          j++;

          if (isMatch(s, p, i, j)) return true;
        } else {
          while (!stars.empty() && stars.front() != s[i]) {
            stars.pop();
          }

          if (stars.empty()) return false;

          cout << stars.front() << "* is matched" << endl;

          i++;
          continue;
        }
      }

      cout << "s[" << i << "] (" << s[i] << ")";
      cout << " : ";
      cout << "p[" << j << "] (" << p[j] << ")" << endl;

      if (s[i] != p[j] && p[j] != '.') return false;

      i++;
      j++;
    }
  }
} solution;

int main() {
  // cout << solution.isMatch("aa", "aa") << endl;
  // cout << solution.isMatch("aa", "a") << endl;
  // cout << solution.isMatch("aa", "b*a*") << endl;
  // cout << solution.isMatch("daab", "dc*a*b") << endl;
  // cout << solution.isMatch("aaa", "ab*a*c*a") << endl;
  // cout << solution.isMatch("aaa", "a*a") << endl;
  cout << solution.isMatch("mississippi", "mis*is*ip*.") << endl;

  return 0;
}