#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 有想到用 hashmap + vector 處理
 * 正在想怎麼讓 remove 也是 O(1)
 * 看一下討論區不小心就看到答案了 QQ
 */

class RandomizedSet {
 public:
  RandomizedSet() {}
  bool insert(int val) {
    if (m.find(val) != m.end()) return false;
    nums.emplace_back(val);
    m[val] = nums.size() - 1;
    return true;
  }

  bool remove(int val) {
    if (m.find(val) == m.end()) return false;
    int last = nums.back();
    m[last] = m[val];
    nums[m[val]] = last;
    nums.pop_back();
    m.erase(val);
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() { return nums[rand() % nums.size()]; }

 private:
  vector<int> nums;
  unordered_map<int, int> m;
};