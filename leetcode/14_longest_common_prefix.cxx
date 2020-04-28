#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string> &strs) {
    int strsLength = strs.size();

    if (strsLength == 0) return "";
    if (strsLength == 1) return strs[0];

    int length = strs[0].size();
    char cs[length + 1];

    for (int i = 0; i < length; i++) {
      for (int j = 1; j < strsLength; j++) {
        if (strs[0][i] == strs[j][i]) continue;
        
        cs[i] = '\0';

        return string(cs);
      }

      cs[i] = strs[0][i];
    }

    cs[length] = '\0';

    return string(cs);
  }
} solution;

int main() {
  vector<string> strs = {"a", "b"};

  cout << solution.longestCommonPrefix(strs) << endl;
}