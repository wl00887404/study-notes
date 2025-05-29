
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * 如果有環，回傳 -1
 * 想辦法找到最長的 path，並算出最多同樣顏色的節點數量
 *
 * 哪些點是起點？
 * edges 跑一輪，沒有被放在 edges[1] 的節點
 * 然後依據起點開始跑，遇到有拜訪過的節點就是環
 * DFS 嗎？
 */

/**
 * 直接 DFS 會 TLE，有些節點會被重複拜訪
 * 感覺可以儲存每個 colorCount
 *
 * 自己的 colorCount = children 的 colorCount + 自己的顏色
 * 全部儲存感覺太大了
 *
 * 如果多條路可以通到同一個節點，能不能提早決定要走哪一條
 * 3 => 4 => 5 => 6
 * 3 => 5, 3 => 6, 3 => 7 這些都可以不用走
 */

class TleSolution {
 public:
  string* colorsP;
  vector<vector<int>> graph;
  unordered_map<char, int> colorCount;
  unordered_set<int> nodesInPath;
  int result;

  int largestPathValue(string colors, vector<vector<int>>& edges) {
    colorsP = &colors;
    result = 0;
    int size = colors.size();
    vector<bool> begin(size, true);
    graph.resize(size);

    for (vector<int>& edge : edges) {
      begin[edge[1]] = false;
      graph[edge[0]].push_back(edge[1]);
    }

    bool hasBegin = false;
    for (int i = 0; i < size; i++) {
      if (!begin[i]) continue;
      helper(i);
      hasBegin = true;
    }

    if (!hasBegin) return -1;
    return result;
  }

  void helper(int i) {
    cout << i << endl;
    if (nodesInPath.count(i)) {
      result = -1;
      return;
    }

    string& colors = *colorsP;
    colorCount[colors[i]]++;
    nodesInPath.insert(i);

    if (result != -1) {
      result = max(result, colorCount[colors[i]]);
    }

    for (const int& child : graph[i]) {
      helper(child);
      if (result == -1) return;
    }

    colorCount[colors[i]]--;
    nodesInPath.erase(i);
  }
};

/**
 * 換個想法，每個節點只有一個顏色，只會改變一個顏色的最佳結果
 * 就算有很多子節點，都取最大的那個就好了
 * 也就是「此節點底下的顏色最多幾個」
 */

/**
 * 他還有一些超 edge 的 case，像是
 * 有一個碰不到的環： colors = "aaa", edges = [[1, 2], [2, 1]]
 * 沒有任何 edge： colors = "g"", edges = []
 */

class Node {
 public:
  bool begin = true;
  char color;
  vector<Node*> children;
  unordered_map<char, int> result;
};

class Solution {
 public:
  unordered_set<Node*> nodesInPath;
  int result;
  int notVisitedCount;

  int largestPathValue(string colors, vector<vector<int>>& edges) {
    int size = colors.size();
    vector<Node*> nodes(size);
    result = 1;  // 就算沒有邊，起碼也有一個顏色
    notVisitedCount = size;

    for (int i = 0; i < size; i++) {
      nodes[i] = new Node();
      nodes[i]->color = colors[i];
    }

    for (const vector<int>& edge : edges) {
      const int& from = edge[0];
      const int& to = edge[1];
      nodes[to]->begin = false;
      nodes[from]->children.push_back(nodes[to]);
    }

    bool hasBegin = false;
    for (Node* node : nodes) {
      if (!node->begin) continue;
      hasBegin = true;
      if (helper(node)) return -1;
    }

    if (!hasBegin || notVisitedCount != 0) return -1;

    return result;
  }

  // return true 就是遇到環了
  bool helper(Node* node) {
    if (nodesInPath.count(node)) return true;
    if (!node->result.empty()) return false;

    nodesInPath.insert(node);
    node->result[node->color] = 1;

    for (Node* child : node->children) {
      if (helper(child)) return true;

      for (const pair<char, int>& p : child->result) {
        const char& c = p.first;
        const int& count = p.second;

        node->result[c] =
            max(node->result[c], count + (c == node->color ? 1 : 0));
        result = max(result, node->result[c]);
      }
    }

    notVisitedCount--;
    nodesInPath.erase(node);

    return false;
  }
};