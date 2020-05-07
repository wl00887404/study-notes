#include <iostream>
#include <unordered_set>
using namespace std;

/**
 * 這題讚怎麼這麼多？
 */

class Solution {
 public:
  int numJewelsInStones(string J, string S) {
    unordered_set<char> jewels;

    for (char& j : J) jewels.insert(j);

    int result = 0;
    for (char& s : S) {
      if (jewels.count(s)) result++;
    }

    return result;
  }
};