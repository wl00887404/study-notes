#include <iostream>
#include <unordered_set>
#include <vector>

#include "./log.cxx"
using namespace std;

/**
 * 結果 brute force 比 recursive 還快
 */

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> results = {};

    generateParenthesis(results, n, n, "");

    return results;
  }

  void generateParenthesis(vector<string>& results, int left, int right,
                           string result) {
    if (left == 0 && right == 0) return results.push_back(result);
    if (left > 0) generateParenthesis(results, left - 1, right, result + "(");
    if (right > left) {
      generateParenthesis(results, left, right - 1, result + ")");
    }
  }
} solution;

int main() {
  vector<string> result = solution.generateParenthesis(4);

  log(result);

  return 0;
}
