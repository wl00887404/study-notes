
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  long long dividePlayers(vector<int>& skill) {
    int size = skill.size();
    int targetSum = 0;
    unordered_map<int, int> map;

    for (int& s : skill) {
      map[s]++;
      targetSum += s;
    }

    // 目標總和是平均的 2 倍
    targetSum *= 2;

    // 整數 + 整數一定是整數，不能整除 targetSum 就不合法
    if (targetSum % size != 0) return -1;

    targetSum /= size;
    long long result = 0;

    for (int& s : skill) {
      // 沒有辦法變成 targetSum
      if (map[targetSum - s] == 0) return -1;

      result += (long long)s * (targetSum - s);

      // 把 targetSum 用掉了
      map[targetSum - s]--;
    }

    // 小 * 大做了一遍，大 * 小也做了一遍，所以要 / 2
    return result / 2;
  }
};