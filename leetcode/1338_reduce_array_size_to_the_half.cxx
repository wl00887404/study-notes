#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int minSetSize(vector<int>& arr) {
    unordered_map<int, int> map;
    for (int& num : arr) {
      map[num] = map.count(num) ? map[num] + 1 : 1;
    }

    priority_queue<pair<int, int>> pq;

    for (const pair<int, int>& p : map) {
      pq.push({p.second, p.first});
    }

    int result = 0;
    int size = arr.size();

    while (!pq.empty() && 2 * size > arr.size()) {
      size -= pq.top().first;
      result++;
        pq.pop();
    }

    return result;
  }
};