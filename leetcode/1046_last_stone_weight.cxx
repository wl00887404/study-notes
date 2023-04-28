#include <iostream>
#include <queue>

using namespace std;

class Solution {
 public:
  int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq;
    for (int& stone : stones) {
      pq.push(stone);
    }

    int size = stones.size();
    while (size > 1) {
      int stone1 = pq.top();
      pq.pop();
      int stone2 = pq.top();
      pq.pop();

      if (stone1 == stone2) {
        // 相同就不用放石頭進去了
        size -= 2;
        continue;
      }

      pq.push(stone1 - stone2);
      size--;
    }

    return size == 1 ? pq.top() : 0;
  }
};