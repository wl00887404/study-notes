#include <iostream>
#include <vector>
using namespace std;

/**
 * TODO: 研究 dp answer
 */

/**
 * 2021/9/1
 * 自從會了 Trie 看 Suffix Tree 比較輕鬆了
 * 但我還是不知道有什麼用
 */

class Solution {
 public:
  bool isMatch(string s, string p) { return isMatch(s, p, 0, 0); }

  bool isMatch(string& s, string& p, int i, int j) {
    int sLength = s.length();
    int pLength = p.length();

    while (true) {
      if (j + 1 < pLength && p[j + 1] == '*') {
        int k = 0;
        int skip = 0;

        // skip p = "a*a*" | ".*a*b*"
        while (j + skip + 3 < pLength &&
               (p[j] == '.' || p[j + skip] == p[j + skip + 2]) &&
               p[j + skip + 3] == '*') {
          skip += 2;
        }

        while (i + k < sLength && (p[j] == s[i + k] || p[j] == '.')) {
          if (isMatch(s, p, i + k, j + skip + 2)) return true;

          k++;
        }

        /**
         * s = "aab" p = "a*b"
         * L49 的 while 只會跑到 s = "ab" p = "b"
         * 最後補跑 s = "b" p = "b"
         */
        if (k != 0 && isMatch(s, p, i + k, j + skip + 2)) return true;

        j += skip + 2;
        continue;
      }

      if (i == sLength && j == pLength) return true;
      if (i == sLength || j == pLength) return false;
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
  // cout << solution.isMatch("aab", "c*a*b") << endl;
  // cout << solution.isMatch("aaa", "ab*a*c*a") << endl;
  // cout << solution.isMatch("aaa", "a*a") << endl;
  // cout << solution.isMatch("", "c*c*") << endl;
  // cout << solution.isMatch("mississippi", "mis*is*p*.") << endl;
  // cout << solution.isMatch("mississippi", "mis*is*ip*.") << endl;

  return 0;
}