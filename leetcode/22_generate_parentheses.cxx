#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * 1: (1)
 * 2: (1, 1)
 * 3: (1, 2)
 * 4: (1, 3) (2, 2)
 * 5: (1, 4) (2, 3)
 */

unordered_map<int, vector<string>> cache = {{1, {"()"}}};

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    if (cache.count(n)) return cache[n];

    unordered_set<string> set;
    vector<string> result;

    for (string str : generateParenthesis(n - 1)) set.insert("(" + str + ")");

    for (int i = 1; i <= n - i; i++) {
      cout << n << ": (" << i << ", " << n - i << ")" << endl;
      vector<string> p1 = generateParenthesis(i);
      vector<string> p2 = generateParenthesis(n - i);

      for (string prefix : p1) {
        for (string str : p2) {
          set.insert(str + prefix);
          set.insert(prefix + str);
        }
      }
    }

    for (string str : set) result.push_back(str);

    cache[n] = result;

    return result;
  }
} solution;

int main() {
  vector<string> result = solution.generateParenthesis(4);

  cout << result.size() << endl;

  for (string str : result) {
    cout << str << endl;
  }

  return 0;
}
