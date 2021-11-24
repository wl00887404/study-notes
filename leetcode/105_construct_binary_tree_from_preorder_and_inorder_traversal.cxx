#include <iostream>
#include <vector>

#include "./TreeNode.cxx"
using namespace std;

/**
 * pre-order in-order
 * http://alrightchiu.github.io/SecondRound/binary-tree-traversalxun-fang.html
 *
 * 超讚的 Binary Tree 視覺化頁面
 * http://btv.melezinek.cz/binary-search-tree.html
 *
 * pre-order 一直往左下衝
 * 遇到 in-order 相同表示到最左了
 * 遇到自己時，不知道右節點的位置
 */

/**
 * 從 106 得到的啟示
 * preorder 一個是 中心 左下中心 左下下中心
 * postorder 則是由後往前 右下下中心、右下中心 中心
 * inorder 則是由左至右依照順序
 *
 * preorder [3, 9, 20, 15, 7]
 * inorder [9, 3, 15, 20, 7]
 *
 * 所以 preorder 依序可以建立最左邊所有節點
 * inorder[0] 是最左側的節點
 * inorder[1] 表示 parent 或是 right
 * 所以只需要判斷是否為 parent
 * 不是 parent 就開始 build 右子樹
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

    TreeNode* node = new TreeNode();
    node->val = preorder[i];
    i++;

    // 瘋狂插入左節點
    // 如果剛插入的節點不是最後一個左節點
    if (preorder[i - 1] != inorder[j]) {
      node->left = buildTree(preorder, inorder, i, j, node);
    }

    j++;
    /**
     * inorder[j] 可能是 parent 或是 right 的最左端
     * 
     */
    if (j < inorder.size() && (!parent || parent->val != inorder[j])) {
      node->right = buildTree(preorder, inorder, i, j, parent);
    }

    return node;
  }
};
