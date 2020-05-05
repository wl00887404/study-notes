#include <iostream>
using namespace std;

/**
 * 這題似乎是字串處理的經典題目呢
 * 直接把解寫在 Hint2 = =
 * 
 * http://www.csie.ntnu.edu.tw/~u91029/LongestCommonSubsequence.html
 * https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
 * https://en.wikipedia.org/wiki/Hirschberg%27s_algorithm
 */

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int length1 = text1.size();
    int length2 = text2.size();
    int dp[length1 + 1][length2 + 1];
    
    for (int i = 0; i < length1 + 1; i++) dp[i][0] = 0;
    for (int i = 0; i < length2 + 1; i++) dp[0][i] = 0;

    for (int i = 0; i < length1; i++) {
      for (int j = 0; j < length2; j++) {
        if (text1[i] == text2[j]) {
          dp[i + 1][j + 1] = dp[i][j] + 1;
        } else {
          dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }
      }
    }

    return dp[length1][length2];
  }
} solution;

int main() {
  cout << solution.longestCommonSubsequence("abcde", "axbcdx") << endl;

  return 0;
}