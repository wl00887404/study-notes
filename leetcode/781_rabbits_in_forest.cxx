#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * 這題不是 distinct 加起來
 *
 * 1st 兔子說，還有 2 隻與他顏色相同，假設他是紅色
 * 2nd 兔子說，還有 2 隻與他顏色相同，假設他是紅色
 * 3rd 兔子說，還有 2 隻與他顏色相同，假設他是紅色
 * 4th 兔子說，還有 2 隻與他顏色相同，他不可能是紅色的
 */

class Solution {
 public:
  int numRabbits(vector<int>& answers) {
    unordered_map<int, int> remainMap;
    int result = 0;

    for (int& answer : answers) {
      result++;

      if (remainMap.count(answer) && remainMap[answer] > 0) {
        // answer 顏色的兔子提及過這隻兔子
        remainMap[answer]--;
        continue;
      }

      // 這是第一隻回報某顏色的兔子
      // 或是，不可能再有某顏色的兔子了
      remainMap[answer] = answer;  // 還可以容納某顏色的兔子 answer 隻
    }

    for (const pair<int, int>& p : remainMap) {
      // 補上兔子提及，但是沒有被問到的兔子們
      result += p.second;
    }

    return result;
  }
};