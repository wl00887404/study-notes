#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 有想到用 hashmap + vector 處理
 * 正在想怎麼讓 remove 也是 O(1)
 * 看一下討論區不小心就看到答案了 QQ
 */

/**
 * TODO: 等忘記時再寫一次
 */

class RandomizedSet {
 public:
  RandomizedSet() {}
  bool insert(int val) {
    if (map.find(val) != map.end()) return false;
    nums.emplace_back(val);
    map[val] = nums.size() - 1;
    return true;
  }

  bool remove(int val) {
    if (map.find(val) == map.end()) return false;
    int last = nums.back();
    map[last] = map[val];
    nums[map[val]] = last;
    nums.pop_back();
    map.erase(val);
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() { return nums[rand() % nums.size()]; }

 private:
  vector<int> nums;
  unordered_map<int, int> map;
};