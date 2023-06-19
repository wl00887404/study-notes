#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 做成一個查詢樹吧？
 */

/**
 * 把 value 從 Node 中抽出來之後
 * 記憶體狀況沒有比較好，哭呀
 */

class Node {
 public:
  unordered_map<int, Node*> children;
  int value;

  Node() { value = 0; }

  void insert(vector<int>::const_iterator begin,
              vector<int>::const_iterator end) {
    if (begin == end) {
      value++;
      return;
    };

    const int& value = *begin;

    if (!children.count(value)) {
      children[value] = new Node();
    }

    children[value]->insert(begin + 1, end);
  }
};

class Solution {
 public:
  int equalPairs(vector<vector<int>>& grid) {
    Node root = Node();

    for (const vector<int>& column : grid) {
      root.insert(column.begin(), column.end());
    }

    int result = 0;
    int m = grid.size();
    int n = grid[0].size();

    for (int j = 0; j < n; j++) {
      Node* pointer = &root;
      for (int i = 0; i < m; i++) {
        int& value = grid[i][j];

        if (!pointer->children.count(value)) break;

        pointer = pointer->children[value];
        if (i == m - 1) {
          result += pointer->value;
        }
      }
    }

    return result;
  }
};