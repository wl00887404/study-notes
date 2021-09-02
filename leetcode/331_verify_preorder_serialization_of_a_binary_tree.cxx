#include <iostream>

using namespace std;

class Solution {
 public:
  bool isValidSerialization(string preorder) {
    string::iterator p = preorder.begin();
    string::iterator end = preorder.end();
    int childrenCount = 1;

    while (p != end && childrenCount != 0) {
      if (*p == '#') {
        childrenCount--;
      } else {
        childrenCount++;
      }

      while (p != end && *p != ',') p++;
      if (p != end) p++;  // , 之後
    }

    return childrenCount == 0 && p == end;
  }
} solution;

int main() {
  //   cout << solution.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") <<
  //   endl;
  cout << solution.isValidSerialization("#,7,6,9,#,#,#") << endl;

  return 0;
}
