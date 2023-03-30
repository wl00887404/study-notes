#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<int>> forwards(n);
    vector<vector<int>> backwards(n);
    vector<bool> arrived(n, false);

    for (vector<int>& c : connections) {
      forwards[c[0]].push_back(c[1]);   // 順向
      backwards[c[1]].push_back(c[0]);  // 逆向
    }

    int result = 0;
    queue<int> q;
    arrived[0] = true;
    q.push(0);

    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        int& current = q.front();
        for (int& next : backwards[current]) {
          // 可以從 next 回到 current
          // 方向不用改變
          if (arrived[next]) continue;
          q.push(next);
        }
        for (int& next : forwards[current]) {
          // 可以從 current 到 next
          // 方向要改變，改成 next 回到 current
          if (arrived[next]) continue;
          q.push(next);
          result++;
        }

        arrived[current] = true;
        q.pop();
      }
    }

    return result;
  }
};