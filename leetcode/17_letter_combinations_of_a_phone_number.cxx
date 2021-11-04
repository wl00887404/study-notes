#include <iostream>
#include <vector>
using namespace std;

/**
 * 這題是 easy 吧
 */

vector<string> digitsLettersMap[] = {{"a", "b", "c"}, {"d", "e", "f"},
                                     {"g", "h", "i"}, {"j", "k", "l"},
                                     {"m", "n", "o"}, {"p", "q", "r", "s"},
                                     {"t", "u", "v"}, {"w", "x", "y", "z"}};

class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    return letterCombinations(digits, 0, {});
  }

  vector<string> letterCombinations(string& digits, int i,
                                    vector<string> results) {
    if (i == digits.size()) return results;

    int digit = digits[i] - '2';

    if (digit < 0 || 7 < digit) {
      return letterCombinations(digits, i + 1, results);
    }

    int resultsLength = results.size();
    vector<string> nextResults;

    if (resultsLength == 0) {
      return letterCombinations(digits, i + 1, digitsLettersMap[digit]);
    }

    int lettersLength = digitsLettersMap[digit].size();

    for (int j = 0; j < resultsLength; j++) {
      for (int k = 0; k < lettersLength; k++) {
        nextResults.push_back(results[j] + digitsLettersMap[digit][k]);
      }
    }

    return letterCombinations(digits, i + 1, nextResults);
  }
} solution;

int main() {
  vector<string> results = solution.letterCombinations("1");

  cout << results.size() << endl;
  for (int i = 0; i < results.size(); i++) {
    cout << results[i] << endl;
  }

  return 0;
}