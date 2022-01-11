#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void reverseString(vector<char>& s) {
    int head = 0;
    int last = s.size() - 1;

    while (head < last) {
      swap(s, head, last);
      head++;
      last--;
    }
  }

  void swap(vector<char>& s, int& i, int& j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
};