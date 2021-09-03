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

/**
 * heap
 *       1
 *      /
 *     2
 *    /
 *   3
 *  /
 * 4
 *
 * 這種右側會產生大量的 null
 * 尷尬慢
 */

// Not Accepted
class HeapCodec {
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
    int i = 0;

    while (pointer != end) {
      string s = "";
      while (*pointer != ' ') s += *pointer++;
      pointer++;  // 移到空白之後

      TreeNode* node = s != "#" ? new TreeNode(stoi(s)) : NULL;
      nodes.push_back(node);

      if (node != NULL) {
        if (i > 0 && i % 2 == 1) {
          // 偶數節點
          nodes[(i - 1) / 2]->left = node;
        } else if (i > 1 && i % 2 == 0) {
          // 奇數節點
          nodes[(i - 2) / 2]->right = node;
        }
      }

      i++;
    }

    return nodes[0];
  };
};