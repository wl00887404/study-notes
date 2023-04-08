#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
/**
 * 看不懂題目哭呀
 * 應該是每艘船有限制重量
 * 一次最多載兩人
 * 所以要是 limit 是 3 ，可以載 (1, 2)
 */

/**
 * 每個人的體重不會超過船的上限
 * 從比較重的人開始登船，在空隙補輕的人上來
 *
 * 假設 limit 是 4
 * 4 的組合， 4, (1, 3), (2, 2),
 * 3 的組合， 3, (2, 1)
 * 2 的組合， 2, (1, 1)
 * 1 的組合， 1
 */

/**
 * 每個組合都數太慢
 * 因為比較重的人只能跟比較輕的搭配
 * 所以可以貪婪演算法，由最重的 + 最輕的開始配對
 * 最重找不到人配對，就只能自己上船
 */

class Solution {
 public:
  int numRescueBoats(vector<int>& weights, int limit) {
    sort(weights.begin(), weights.end());

    int result = 0;
    int left = 0;
    int right = weights.size() - 1;

    while (left < right) {
      int& light = weights[left];
      int& heavy = weights[right];

      // 最輕跟最重合起來不能一起上船 => 最重必須獨立上船
      if (light + heavy > limit) {
        result++;
        right--;
        continue;
      }

      // 最輕跟最重可以一起上船
      result++;
      right--;
      left++;
    }

    // 配剩的人，只能自己上船
    if (left == right) result++;

    return result;
  }
};

class WithMapSolution {
 public:
  int numRescueBoats(vector<int>& people, int limit) {
    peopleCount = people.size();
    if (limit == 1) return peopleCount;

    for (int& weight : people) {
      if (!peopleCountByWeight.count(weight)) {
        weights.push_back(weight);
        peopleCountByWeight[weight] = 0;
      }

      peopleCountByWeight[weight]++;
    }

    sort(weights.begin(), weights.end());

    int result = 0;
    int left = 0;
    int right = weights.size() - 1;

    while (left < right && peopleCount != 0) {
      int& light = weights[left];
      int& heavy = weights[right];

      // 最輕跟最重合起來不能一起上船 => 最重必須獨立上船
      if (light + heavy > limit) {
        result += peopleCountByWeight[heavy];
        peopleCount -= peopleCountByWeight[heavy];
        peopleCountByWeight[heavy] = 0;
        right--;
        continue;
      }

      // 最輕最重可以一起上船
      int count = min(peopleCountByWeight[light], peopleCountByWeight[heavy]);
      result += count;
      peopleCountByWeight[light] -= count;
      peopleCountByWeight[heavy] -= count;
      peopleCount -= count * 2;

      if (peopleCountByWeight[light] == 0) left++;
      if (peopleCountByWeight[heavy] == 0) right--;
    }

    if (left == right && peopleCount != 0) {
      int& weight = weights[left];
      int count = peopleCountByWeight[weight];
      if (weight * 2 <= limit) {
        result += count / 2 + count % 2;

      } else {
        result += count;
      }
    }

    return result;
  }

  vector<int> weights;
  unordered_map<int, int> peopleCountByWeight;
  int peopleCount;
};