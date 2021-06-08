#include <iostream>
#include <vector>

#include "./TreeNode.cxx"
using namespace std;
/**
 * pre-order in-order
 * http://alrightchiu.github.io/SecondRound/binary-tree-traversalxun-fang.html
 *
 * pre-order 一直往左下衝
 * 遇到 in-order 相同表示到最左了
 * 遇到自己時，不知道右節點的位置
 */
class Solution {
 public:
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

    // 瘋狂插入左節點
    // 如果剛插入的節點不是最後一個
    if (preorder[i - 1] != inorder[j]) {
      root->left = buildTree(preorder, inorder, i, j, root);
    }

    j++;
    /**
     * preorder[i] 會往右上走，所以不知道是哪一個祖先（或自己）的右子節點
     * inorder[j] 是親代或是此節點的右子節點的最左端
     * 如果是親代右側的節點 inorder[j] 會先出親代
     */
    if (j < inorder.size() && (!parent || parent->val != inorder[j])) {
      root->right = buildTree(preorder, inorder, i, j, parent);
    }

    return root;
  }
};
