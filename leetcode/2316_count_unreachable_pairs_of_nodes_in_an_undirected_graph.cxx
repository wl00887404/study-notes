#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 看 Example 2
 * 一共可以分 3 群， 4 + 1 + 2
 * 之後兩兩群的元素互相碰不到
 * 所以是 4 * 1 + 4 * 2 + 1 * 2 = 14
 */

class Solution {
 public:
  long long countPairs(int n, vector<vector<int>>& edges) {
    if (edges.size() == 0) return (long long)n * (n - 1) / 2;

    parents.resize(n);
    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }

    for (vector<int>& edge : edges) {
      int root1 = findParent(edge[0]);
      int root2 = findParent(edge[1]);
      parents[root1] = root2;
    }

    // id, size
    unordered_map<int, int> groupSizeMap;

    for (int i = 0; i < n; i++) {
      int root = findParent(i);
      if (!groupSizeMap.count(root)) groupSizeMap[root] = 0;
      groupSizeMap[root]++;
    }

    /**
     * 下面是我原本 result 的演算法
     * 效率比範例差很多
     * vector<int> groupSizes;
     * for (const pair<int, int>& p : groupSizeMap) {
     *   groupSizes.push_back(p.second);
     * }
     * int size = groupSizes.size();
     * long long result = 0;
     * for (int i = 0; i < size; i++) {
     *   for (int j = i + 1; j < size; j++) {
     *     result += (long long)groupSizes[i] * groupSizes[j];
     *   }
     * }
     * return result;
     */

    // 抄襲範例的演算法
    long long numberOfPaths = 0;
    long long remainingNodes = n;
    for (auto component : groupSizeMap) {
      int componentSize = component.second;
      numberOfPaths += componentSize * (remainingNodes - componentSize);
      remainingNodes -= componentSize;
    }

    return numberOfPaths;
  }

  vector<int> parents;

  int findParent(int n) {
    // 如果是自己就是 root ，直接回傳
    if (parents[n] == n) return n;

    int root = findParent(parents[n]);
    parents[n] = root;

    return root;
  }
};
