#include <iostream>
#include <stack>
using namespace std;

/**
 * 自己寫出來 4ms
 * 豪爽喔
 *
 * TODO: leetcode solution 有 4 個解答 有空記得看一下
 */

class Solution {
 public:
  int longestValidParentheses(string s) {
    int i = 0;
    int result = 0;
    int length = s.size();
    stack<pair<int, int>> lastResults;  // <end(included), length>

    while (true) {
      while (i + 1 < length && !(s[i] == '(' && s[i + 1] == ')')) i++;

      if (i + 1 >= length) return result;

      int start = i;

      while (i < length) {
        if (s[i] == '(') {
          // (
          if (i + 1 < length && s[i + 1] == ')') {
            // ()
            i += 2;
          } else {
            // ((
            lastResults.push({i, i - start});
            break;
          }
        } else {
          // )
          if (start > 0 && s[start - 1] == '(') {
            // ( ()()() )
            start--;
            i++;
            if (!lastResults.empty() && start == lastResults.top().first) {
              start -= lastResults.top().second;
              lastResults.pop();
            }
          } else {
            break;
          }
        }
      }

      result = max(i - start, result);
    }

    return result;
  }
} solution;

int main() {
  // cout << solution.longestValidParentheses("((()))())") << endl;
  // cout << solution.longestValidParentheses("((()((") << endl;
  // cout << solution.longestValidParentheses("()(((())))") << endl; // 10
  cout << solution.longestValidParentheses("()(((()(()))))") << endl;  // 14

  return 0;
}