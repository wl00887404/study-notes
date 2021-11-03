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
 * 直接指定 index 好了
 */

/**
 * 看其他 submit
 * 修剪掉多餘的 null 應該是可行的
 */

/**
 * 搭配 105
 * inorder 是 左 → 自己 → 右
 * preorder 是 自己 → 左 → 右
 *
 * 遇到重複的值該怎麼辦？
 */

// WIP: 搭配 105
// 這個作法應該不太可能
// 105 的重點是裡面的元素的不一樣
// 遇到一樣的不知道怎麼處理
class Codec {
 public:
  string serialize(TreeNode* root) {
    if (root == NULL) return "";

    return getPreorderString(root) + "|" + getInorderString(root);
  }

  TreeNode* deserialize(string data) {
    string::iterator pointer = data.begin();
    string::iterator end = data.end();

    if (pointer == end) return NULL;

    vector<int> preorder;
    vector<int> inorder;

    while (*pointer != '|') {
      string s = "";
      while (*pointer != ' ') s += *pointer++;
      preorder.push_back(stoi(s));
      pointer++;  // 跳過空白
    }
    pointer++;  // 跳過 |

    while (pointer != end) {
      string s = "";
      while (*pointer != ' ') s += *pointer++;
      inorder.push_back(stoi(s));
      pointer++;  // 跳過空白
    }

    return buildTree(preorder, inorder);
  }

 private:
  string getInorderString(TreeNode* node) {
    string result = "";
    if (node->left != NULL) result += getInorderString(node->left);
    result += to_string(node->val) + " ";
    if (node->right != NULL) result += getInorderString(node->right);

    return result;
  }

  string getPreorderString(TreeNode* node) {
    string result = to_string(node->val) + " ";
    if (node->left != NULL) result += getPreorderString(node->left);
    if (node->right != NULL) result += getPreorderString(node->right);

    return result;
  }

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int i = 0;
    int j = 0;
    return buildTree(preorder, inorder, i, j, NULL);
  }

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int& i,
                      int& j, TreeNode* parent) {
    if (i >= preorder.size()) return NULL;

    TreeNode* root = new TreeNode();
    root->val = preorder[i];
    i++;

    if (preorder[i - 1] != inorder[j]) {
      root->left = buildTree(preorder, inorder, i, j, root);
    }

    j++;

    if (j < inorder.size() && (!parent || parent->val != inorder[j])) {
      root->right = buildTree(preorder, inorder, i, j, parent);
    }

    return root;
  }
};

// Accepted: 直接指定 node 編號
class IndexCodec {
 public:
  string serialize(TreeNode* root) {
    if (root == NULL) return "";

    int increment = 0;

    return helper(root, increment, -1, true);
    ;
  }

  TreeNode* deserialize(string data) {
    string::iterator pointer = data.begin();
    string::iterator end = data.end();

    if (pointer == end) return NULL;

    vector<TreeNode*> nodes;
    string s = "";

    while (pointer != end && *pointer != ' ') {
      s += *pointer++;
    }
    pointer++;  // 跳過空白

    TreeNode* root = new TreeNode(stoi(s));
    nodes.push_back(root);

    while (pointer != end) {
      s = "";
      while (*pointer != '<' && *pointer != '>') {
        s += *pointer++;
      }
      bool isLeft = *pointer == '<';
      pointer++;  // 跳過 < 與 >

      int parentIndex = stoi(s);

      s = "";
      while (*pointer != ' ') {
        s += *pointer++;
      }
      pointer++;  // 跳過空白
      TreeNode* node = new TreeNode(stoi(s));

      if (isLeft) {
        nodes[parentIndex]->left = node;
      } else {
        nodes[parentIndex]->right = node;
      }

      nodes.push_back(node);
    }

    return root;
  }

 private:
  string getPrefix(int& parentIndex, bool& isLeft) {
    if (parentIndex == -1) return "";

    return to_string(parentIndex) + (isLeft ? "<" : ">");
  }

  string helper(TreeNode* node, int& increment, int parentIndex, bool isLeft) {
    int index = increment++;
    string prefix = getPrefix(parentIndex, isLeft);
    string result = prefix + to_string(node->val) + " ";

    if (node->left != NULL) {
      result += helper(node->left, increment, index, true);
    }

    if (node->right != NULL) {
      result += helper(node->right, increment, index, false);
    }

    return result;
  }
};

// Not Accepted: Heep 陣列
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