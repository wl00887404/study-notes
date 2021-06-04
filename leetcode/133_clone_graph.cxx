#include <iostream>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    Node* map[101];
    for (int i = 0; i < 101; i++) map[i] = NULL;

    return cloneGraph(node, map);
  }

  Node* cloneGraph(Node* node, Node** map) {
    if (node == NULL) return NULL;
    if (map[node->val] != NULL) return map[node->val];

    Node* pointer = new Node();
    pointer->val = node->val;
    map[node->val] = pointer;

    for (Node* neighbor : node->neighbors) {
      Node* cloneNeighbor = cloneGraph(neighbor, map);
      pointer->neighbors.push_back(cloneNeighbor);
    }

    return pointer;
  }
};