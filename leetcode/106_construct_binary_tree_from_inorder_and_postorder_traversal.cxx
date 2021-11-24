#include <iostream>
#include <unordered_map>
#include <vector>

#include "./TreeNode.cxx"
using namespace std;

/**
 * 與 105 的類似題
 *
 * inorder 左中右
 * postorder 左右中
 *
 * inorder 前兩項可以確定此樹範圍
 * postorder 在中間出現之前都是右邊
 *
 * 完整一點考量
 * inorder 最左 parent 右邊的下一個最左 再右邊的下一個最左 parent 右邊 右邊 右邊
 * postorder 最左 右邊的下一個最左 再右邊的下一個最左 parent
 *
 * inorder 在 parent 後不知道是「右邊的下一個最左」還是「右側」
 * postorder 能夠幫忙 inorder 確認 parent 與最左之間的元素數量
 *
 * 在 postorder 的 parent 出現的前一位會是右側！
 */

/**
 * 欸不是
 * inorder 到底有個屁用呀
 * 左側右側關係確定
 *
 * postorder 後面往前
 * 一定是 中心 中心 ... 中心 右側
 *
 * postorder 的 n 項以前
 * 這些節點一定都比 n 還深
 *
 * 最後一個中心找在 inorder 的位置
 * 可以確定左側 中心 右側
 * 在 postoder 也可以確定 左側 右側 中心
 */

class Solution {
 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int size = inorder.size();
    inorderPointer = &inorder;
    postorderPointer = &postorder;

    for (int i = 0; i < size; i++) {
      inorderIndexByValue[inorder[i]] = i;
    }

    last = size - 1;

    return buildTree(0, size);
  }

  TreeNode* buildTree(int left, int right) {
    if (left >= right) return NULL;
    
    vector<int>& inorder = *inorderPointer;
    vector<int>& postorder = *postorderPointer;

    TreeNode* node = new TreeNode(postorder[last]);
    int& parentInorderIndex = inorderIndexByValue[postorder[last]];

    last--;
    if (right - left == 1) return node;

    int& childInorderIndex = inorderIndexByValue[postorder[last]];

    // 有右側節點
    if (parentInorderIndex < childInorderIndex) {
      node->right = buildTree(parentInorderIndex + 1, right);
    }

    if (last == -1) return node;

    node->left = buildTree(left, parentInorderIndex);

    return node;
  }

  vector<int>* inorderPointer;
  vector<int>* postorderPointer;
  unordered_map<int, int> inorderIndexByValue;
  int last;
} solution;

int main() {
  vector<int> inorder = {1, 2, 3, 4};
  vector<int> postorder = {1, 4, 3, 2};
  solution.buildTree(inorder, postorder);

  return 0;
}