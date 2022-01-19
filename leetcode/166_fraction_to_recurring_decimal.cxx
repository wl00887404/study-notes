#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 就仿人類除法呀
 * 不然還能怎樣
 *
 * 難怪倒讚這麼多
 */

class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) return "0";

    // 兩者異號結果會有負號
    string part1 = getSign(numerator) * getSign(denominator) < 0 ? "-" : "";

    long long clone = abs(numerator);
    denominator = abs(denominator);

    part1 += to_string(clone / denominator);
    clone %= denominator;

    // 沒有小數直接 return
    if (clone == 0) return part1;

    part1 += '.';

    // 數值, 第一次出現的位置
    unordered_map<int, int> map;
    map[0] = 0;
    string part2 = "";
    int i = 0;

    while (!map.count(clone)) {
      map[clone] = i;
      // 補零繼續除
      clone *= 10;
      part2 += to_string(clone / denominator);
      clone %= denominator;
      i++;
    }

    if (clone == 0) return part1 + part2;

    // part1 + 不重複的部份 + (重複部份)
    return part1 + part2.substr(0, map[clone]) + "(" +
           part2.substr(map[clone]) + ")";
  }

  int getSign(int& x) { return x < 0 ? -1 : 1; }
};