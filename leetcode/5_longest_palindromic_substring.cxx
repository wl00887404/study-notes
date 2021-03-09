#include <algorithm>
#include <iostream>
using namespace std;

/**
 * brute force: 2e79360
 *
 * TODO: Manacher’s Algorithm
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

int main() {
  cout << solution.longestPalindrome("babad") << endl;  // bab
  // cout << solution.longestPalindrome("cbbd") << endl;   // bb
  // cout << solution.longestPalindrome("ac") << endl;      // a
  // cout << solution.longestPalindrome("ccc") << endl;     // ccc
  // cout << solution.longestPalindrome("abcba") << endl;   // abcba
  // cout << solution.longestPalindrome("abacab") << endl;  // bacab

  // cout << solution.getPalindromeLength("abcbar", 2, 2) << endl;
  // cout << solution.getPalindromeLength("bc", 0, 1) << endl;
  return 0;
}