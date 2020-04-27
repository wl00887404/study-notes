#include <iostream>
#include <regex>
using namespace std;

/**
 * 後面有一堆超肥的 testcase
 * 正常的 regex 會跑不完
 *
 * 我棄權 直接看解答
 * .* 會 match 任何字串
 * 只要過了一個就回去了
 * s = "dogdogcatcat" p = "d*ogc*at"
 * 結果不會是 d(ogd)ogc(atc)at
 * 而是 d()og(dogcat)cat
 * 因此只要不符合時
 * 只要回到最後一個 star 就行了
 *
 * TODO: 研究 dp answer
 */

class Solution {
 public:
  bool isMatch(string s, string p) { return isMatch(s, p, 0, 0); }

  bool isMatch(string& s, string& p, int i = 0, int j = 0) {
    int sLength = s.size();
    int pLength = p.size();
    int lastStar[2] = {-1};

    while (true) {
      if (p[j] == '*') {
        do {
          j++;
        } while (j < pLength && p[j] == '*');

        lastStar[0] = i;
        lastStar[1] = j;

        continue;
      }

      if (i == sLength && j == pLength) return true;
      if (i == sLength && j != pLength) return false;

      if (s[i] != p[j] && p[j] != '?') {
        if (lastStar[0] == -1) return false;

        lastStar[0]++;
        i = lastStar[0];
        j = lastStar[1];
        continue;
      }

      i++;
      j++;
    }
  }
} solution;

int main() {
  // cout << solution.isMatch("aa", "*") << endl;
  // cout << solution.isMatch("acdcb", "a*c?b") << endl;
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