#include <iostream>
#include <queue>
#include <vector>

#include "./TreeNode.cxx"
using namespace std;

/**
 * 來個 heap 的版本吧！
 *      1
 *    /  \
 *   2   3
 *  /\   /\
 * 4 5  6 7
 *
 * 1 2 3 4 5 6
 *
 * 1 => 2 3
 * 2 => 4 5
 * 3 => 6 7
 */

class Codec {
 public:
  string serialize(TreeNode* root) {
    if (root == NULL) return "# ";
    queue<TreeNode*> queue;
    string result = "";
    queue.push(root);

    while (true) {
      int length = queue.size();
      int childCount = 0;

      while (length--) {
        if (queue.front() == NULL) {
          queue.push(NULL);
          queue.push(NULL);
          result += "# ";
        } else {
          queue.push(queue.front()->left);
          if (queue.front()->left != NULL) childCount++;
          queue.push(queue.front()->right);
          if (queue.front()->right != NULL) childCount++;

          result += to_string(queue.front()->val) + " ";
        }
        queue.pop();
      }

      if (childCount == 0) break;
    }

    return result;
  }

  TreeNode* deserialize(string data) {
    vector<TreeNode*> nodes;
    string::iterator pointer = data.begin();
    string::iterator end = data.end();
    while (pointer != end) {
      string s = "";
      while (*pointer != ' ') s += *pointer++;
      pointer++;  // 移到空白之後

      nodes.push_back(s != "#" ? new TreeNode(stoi(s)) : NULL);
    }

    int length = nodes.size();

    for (int i = 0; i < length; i++) {
      int leftIndex = i * 2 + 1;
      if (leftIndex < length && nodes[leftIndex]) {
        nodes[i]->left = nodes[leftIndex];
      }

      int rightIndex = i * 2 + 2;
      if (rightIndex < length && nodes[rightIndex]) {
        nodes[i]->right = nodes[rightIndex];
      }
    }

    return nodes[0];
  };
};