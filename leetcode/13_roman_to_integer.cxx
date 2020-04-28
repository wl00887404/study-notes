#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int romanToInt(string s) {
    string::iterator begin = s.begin();
    string::iterator end = s.begin();
    int result = 0;

    unordered_map<char, int> map = {
        {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000},
    };

    while (begin != end) {
      if (*begin == 'C' && *(begin + 1) == 'M') {
        result += 900;
        begin += 2;
        continue;
      }

      if (*begin == 'C' && *(begin + 1) == 'D') {
        result += 400;
        begin += 2;
        continue;
      }

      if (*begin == 'X' && *(begin + 1) == 'C') {
        result += 90;
        begin += 2;
        continue;
      }

      if (*begin == 'X' && *(begin + 1) == 'L') {
        result += 40;
        begin += 2;
        continue;
      }

      if (*begin == 'I' && *(begin + 1) == 'X') {
        result += 9;
        begin += 2;
        continue;
      }

      if (*begin == 'I' && *(begin + 1) == 'V') {
        result += 4;
        begin += 2;
        continue;
      }

      result += map[*begin];
      begin++;
    }

    return result;
  }
};
