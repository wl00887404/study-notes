#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0) return "";
    if (strs.size() == 1) return strs[0];

    const char *pointers[strs.size() - 1];
    const char *ref = strs[0].c_str();
    string result = "";

    for (int i = 0; i < strs.size() - 1; i++) {
      pointers[i] = strs[i + 1].c_str();
    }

    while (*ref != '\0') {
      for (int i = 1; i < strs.size(); i++) {
        if (*pointers[i - 1] != *ref) return result;

        pointers[i - 1]++;
      }

      result += *ref;
      ref++;
    }
    return result;
  }
} solution;

int main() {
  vector<string> strs = {"a", "b"};

  cout << solution.longestCommonPrefix(strs) << endl;
}