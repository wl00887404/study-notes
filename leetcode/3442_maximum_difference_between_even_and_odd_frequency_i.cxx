#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxDifference(string s) {
    //  s[i] - 'a'
    vector<int> frequencies(26, 0);

    for (const char& c : s) {
      frequencies[c - 'a']++;
    }

    int maxOdd = 0;
    int minEven = s.size();

    for (int& f : frequencies) {
      if (f % 2 == 1) {
        maxOdd = max(maxOdd, f);
      } else if (f != 0) {
        minEven = min(minEven, f);
      }
    }

    return maxOdd - minEven;
  }
};