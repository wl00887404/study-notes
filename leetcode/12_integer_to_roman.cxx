#include <iostream>
using namespace std;

pair<string, int> pairs[] = {{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
                             {"C", 100},  {"XC", 90},  {"L", 50},  {"XL", 40},
                             {"X", 10},   {"IX", 9},   {"V", 5},   {"IV", 4},
                             {"I", 1}};

class Solution {
 public:
  string intToRoman(int num) {
    string result = "";

    while (num != 0) {
      for (int i = 0; i < 13; i++) {
        if (num >= pairs[i].second) {
          num -= pairs[i].second;
          result += pairs[i].first;
          break;
        }
      }
    }

    return result;
  }
} solution;

int main() {
  cout << solution.intToRoman(3) << endl;

  return 0;
}