#include <iostream>
using namespace std;

/**
 * 後面有一堆超肥的 testcase
 * 正常的 regex 會跑不完
 */

class Solution {
 public:
  bool isMatch(string s, string p) { return isMatch(s, p, 0, 0); }

  bool isMatch(string& s, string& p, int i, int j) {
    int sLength = s.size();
    int pLength = p.size();

    while (true) {
      if (p[j] == '*') {
        do {
          j++;
        } while (j < pLength && p[j] == '*');

        while (i < sLength + 1) {
          if (isMatch(s, p, i++, j)) return true;
        }

        return false;
      }

      if (i == sLength && j == pLength) return true;
      if (i == sLength || j == pLength) return false;
      if (s[i] != p[j] && p[j] != '?') return false;

      i++;
      j++;
    }
  }
} solution;

int main() {
  // cout << solution.isMatch("aa", "*b") << endl;
  cout << solution.isMatch(
              "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababa"
              "abbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbb"
              "aaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaab"
              "aaababaaaabb",
              "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**"
              "aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb")
       << endl;

  return 0;
}