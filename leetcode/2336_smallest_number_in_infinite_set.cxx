#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

/**
 * 這個 set 假定 new 出來包含了所有的正整數
 * popSmallest 會彈出最小的
 * addBack 有可能恢復被 pop 的元素
 */

class SmallestInfiniteSet {
 public:
  int smallest;
  priority_queue<int, vector<int>, greater<int> > pq;
  unordered_set<int> set;

  SmallestInfiniteSet() { smallest = 1; }

  int popSmallest() {
    if (!this->pq.empty()) {
      int result = pq.top();
      pq.pop();
      set.erase(result);

      return result;
    }

    int result = smallest;
    smallest++;

    return result;
  }

  void addBack(int num) {
    // 已經有的數字不用補
    if (num >= smallest) return;
    if (set.count(num)) return;

    pq.push(num);
    set.insert(num);
  }
};
