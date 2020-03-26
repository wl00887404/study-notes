#include <iostream>
using namespace std;

/**
 * 這題要完全 match 耶
 * 只要針對 * 與 . 處理即可，
 * 從後往前比較
 *
 * true 條件
 *   1. ^.*
 *   2. 同時 i == -1 && j ==-1
 * 字元不相符且非 . => false
 * 字元相符 => 迴圈繼續 => i == -1 && j == -1 => true
 */

class Solution {
 public:
  bool isMatch(string s, string p) {
    int sLength = s.length();
    int pLength = p.length();
    int i = sLength - 1;
    int j = pLength - 1;

    // 如果其中一方用盡 (== -1)
    // 即為失敗

    while (true) {
      if (j > 0 && p[j - 1] == '.' && p[j] == '*') {
        cout << "發現 .*" << endl;

        if (j - 2 == -1) return true;

        while (i != -1 && s[i] != p[j - 2]) i--;

        j -= 2;

        cout << "i: " << i << " j: " << j << endl;

        continue;
      }

      if (j > 0 && p[j] == '*') {
        cout << "發現 " << p[j - 1] << "*" << endl;
        while (i != -1 && s[i] == p[j - 1]) i--;

        j -= 2;

        cout << "i: " << i << " j: " << j << endl;

        continue;
      }

      if (i == -1 && j == -1) return true;
      if (i == -1 && j != -1) return false;
      if (i != -1 && j == -1) return false;

      if (s[i] != p[j] && p[j] != '.') return false;

      cout << s[i] << " : " << p[j] << " is matched" << endl;
      cout << "i: " << i << " j: " << j << endl;

      i--;
      j--;
    }
  }
} solution;

int main() {
  // cout << solution.isMatch("aa", "a") << endl;
  // cout << solution.isMatch("aab", "c*a*b") << endl;
  cout << solution.isMatch("aaa", "ab*a*c*a") << endl;

  return 0;
}