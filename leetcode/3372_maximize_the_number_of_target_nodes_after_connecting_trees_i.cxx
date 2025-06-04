#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * 幹題目有夠難看懂
 *
 * 給定兩棵 tree，回傳一個陣列 answer
 * answer[0] 表示 tree1 的 0 節點，可以隨便與 tree2 的節點相連
 * 要達到 k 距離內（包含），可以連結到最多的節點
 *
 * example1 有點奇怪，幹嘛不全連 0 就好
 *
 * 自己的樹有就是某節點的 k 距離 + 另個棵樹某節點的 k - 1 距離
 *
 * 想考量 tree2 的情境
 * 在 k 範圍內要最多的節點，不一定是樹的中心
 *
 * 隨機選一個節點當成樹根，計算到所有子節點的距離
 * 然後子節點的距離 ，等於自己 + parent 與（parent 子節點 + 1）
 */

 /**
  * FIXME: TLE 了 QQ
  */

class Node {
 public:
  int i;
  unordered_set<Node*> children;
  // distance, count
  unordered_map<int, int> distanceCount;
};

class Solution {
 public:
  vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                             vector<vector<int>>& edges2, int k) {
    int m = edges1.size() + 1;
    int n = edges2.size() + 1;

    vector<Node*> nodes1;
    vector<Node*> nodes2;

    applyEdges(m, nodes1, edges1);
    applyEdges(n, nodes2, edges2);

    vector<int> result(m);
    int maximum = 0;
    for (Node* node : nodes2) {
      maximum = max(maximum, getReachableCount(node, k - 1));
    }

    for (int i = 0; i < m; i++) {
      result[i] = getReachableCount(nodes1[i], k) + maximum;
    }

    return result;
  }

  void applyEdges(int size, vector<Node*>& nodes, vector<vector<int>>& edges) {
    nodes.resize(size);

    for (int i = 0; i < size; i++) {
      nodes[i] = new Node();
      nodes[i]->i = i;
    }

    for (const vector<int>& edge : edges) {
      const int& from = edge[0];
      const int& to = edge[1];
      nodes[from]->children.insert(nodes[to]);
      nodes[to]->children.insert(nodes[from]);
    }

    makeTree(nodes[0]);
    helper(nodes[0]);
  }

  void makeTree(Node* node) {
    node->distanceCount[0] = 1;

    for (Node* child : node->children) {
      child->children.erase(node);
      makeTree(child);

      for (const pair<int, int>& p : child->distanceCount) {
        node->distanceCount[p.first + 1] += p.second;
      }
    }
  }

  void helper(Node* node) {
    // parent 不用調整
    // children 的 distanceCount 必須加上 parent 的 distanceCount

    for (Node* child : node->children) {
      unordered_map<int, int> clone = child->distanceCount;

      for (const pair<int, int>& p : node->distanceCount) {
        child->distanceCount[p.first + 1] += p.second - clone[p.first - 1];
      }

      helper(child);
    }
  }

  int getReachableCount(Node* node, int k) {
    int result = 0;
    for (const pair<int, int>& p : node->distanceCount) {
      if (p.first > k) continue;
      result += p.second;
    }
    return result;
  }
};