#include <algorithm>
#include <iostream>
using namespace std;

/**
 * brute force: 2e79360
 */

class Solution {
 public:
  string longestPalindrome(string s) {
    int from = 0;
    int length = 0;

    for (int i = 0; i < s.length(); i++) {
      int palindromeLength =
          max(getPalindromeLength(s, i, i), getPalindromeLength(s, i, i + 1));

      if (palindromeLength > length) {
        length = palindromeLength;
        from = i - palindromeLength / 2 - palindromeLength % 2 + 1;
      }
    }

    return s.substr(from, length);
  }

  int getPalindromeLength(string s, int left, int right) {
    while (true) {
      if (left < 0 || right > s.length() - 1) break;
      if (s[left] != s[right]) break;

      left--;
      right++;
    }

    return right - left - 1;
  }
} solution;

class DpSolution {
 public:
  string longestPalindrome(string s) {
    string reversed = s;
    reverse(reversed.begin(), reversed.end());

    return longestCommonSubstring(s, reversed);
  }
  string longestCommonSubstring(string s1, string s2) {
    int length1 = s1.size();
    int length2 = s2.size();
    int dp[length1 + 1][length2 + 1];

    for (int i = 0; i < length1 + 1; i++) dp[i][0] = 0;
    for (int i = 0; i < length2 + 1; i++) dp[0][i] = 0;

    pair<int, int> result = {1, 1};

    for (int i = 0; i < length1; i++) {
      for (int j = 0; j < length2; j++) {
        if (s1[i] == s2[j]) {
          dp[i + 1][j + 1] = dp[i][j] + 1;

          if (dp[i + 1][j + 1] > dp[result.first][result.second]) {
            result.first = i + 1;
            result.second = j + 1;
          }
        } else {
          dp[i + 1][j + 1] = 0;
        }
      }
    }

    return s1.substr(result.first - dp[result.first][result.second],
                     dp[result.first][result.second]);
  }
} dpSolution;

// Manacher's Algorithm
class BestSolution {
 public:
  string longestPalindrome(string s) {
    /**
     * a => ^#a#$ (1 => 5)
     * aa => ^#a#a#$ (2 => 7)
     * aaa => ^#a#a#a#$ (3 => 9)
     */
    int length = s.length();
    int paddedLength = 2 * length + 3;
    char paddedS[paddedLength];
    int maxIndex = 2;
    int maxRadius = 1;
    paddedS[0] = '^';
    paddedS[paddedLength - 1] = '$';
    for (int i = 1; i < paddedLength - 1; i++) {
      if (i % 2 == 1) {
        paddedS[i] = '#';
      } else {
        paddedS[i] = s[i / 2 - 1];
      }
    }

    for (int i = 1; i < paddedLength - 1; i++) {
      int radius = 0;
      while (paddedS[i + radius + 1] == paddedS[i - radius - 1]) radius++;

      // cout << i << " " << paddedS[i] << ": " << radius << endl;
      if (radius <= maxRadius) continue;
      maxIndex = i;
      maxRadius = radius;
    }

    /**
     *                 # a # b # a # c #  a  #  b  #
     *                       ^       i          ^
     * radius          0 1 0 3 0 1 0 5 0  1  0  1  0
     * padded index    1 2 3 4 5 6 7 8 9 10 11 12 13
     * original index    0   1   2   3    4     5
     */

    return s.substr((maxIndex - maxRadius + 1) / 2 - 1, maxRadius);
  }
} bestSolution;

int main() {
  // cout << solution.longestPalindrome("babad") << endl;  // bab
  // cout << solution.longestPalindrome("cbbd") << endl;   // bb
  // cout << solution.longestPalindrome("ac") << endl;      // a
  // cout << solution.longestPalindrome("ccc") << endl;     // ccc
  // cout << solution.longestPalindrome("abcba") << endl;   // abcba
  // cout << solution.longestPalindrome("abacab") << endl;  // bacab

  // cout << solution.getPalindromeLength("abcbar", 2, 2) << endl;
  // cout << solution.getPalindromeLength("bc", 0, 1) << endl;""

  cout << bestSolution.longestPalindrome("babad") << endl;   // bab
  cout << bestSolution.longestPalindrome("cbbd") << endl;    // bb
  cout << bestSolution.longestPalindrome("ac") << endl;      // a
  cout << bestSolution.longestPalindrome("ccc") << endl;     // ccc
  cout << bestSolution.longestPalindrome("abcba") << endl;   // abcba
  cout << bestSolution.longestPalindrome("abacab") << endl;  // bacab
  return 0;
}