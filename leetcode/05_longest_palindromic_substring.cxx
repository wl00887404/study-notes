#include <iostream>
using namespace std;

/**
 * brute force: 2e79360
 * 
 * TODO: Manacher’s Algorithm 
 */

int max(int x, int y) { return x > y ? x : y; }

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

int main() {
  cout << solution.longestPalindrome("babad") << endl;   // bab
  cout << solution.longestPalindrome("cbbd") << endl;    // bb
  cout << solution.longestPalindrome("ac") << endl;      // a
  cout << solution.longestPalindrome("ccc") << endl;     // ccc
  cout << solution.longestPalindrome("abcba") << endl;   // abcba
  cout << solution.longestPalindrome("abacab") << endl;  // bacab

  // cout << solution.getPalindromeLength("abcbar", 2, 2) << endl;
  // cout << solution.getPalindromeLength("bc", 0, 1) << endl;
  return 0;
}