#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    vector<int>::iterator begin = digits.begin();
    vector<int>::iterator end = digits.end() - 1;

    while (*end == 9) {
      *end = 0;

      if (end == begin) {
        digits.insert(begin, 1);
        return digits;
      }

      end--;
    }

    (*end)++;

    return digits;
  }
};