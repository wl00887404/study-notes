#include <unordered_map>

#include "./TreeNode.cxx"

using namespace std;

class Solution {
 public:
  int countPairs(TreeNode* root, int distance) {
    result = 0;
    this->distance = distance;
    this->root = root;
    unordered_map<int, int> dummyMap;
    helper(root, dummyMap);

    return result;
  }

  int result;
  int distance;
  TreeNode* root;
  void helper(TreeNode* node, unordered_map<int, int>& parentMap) {
    if (node == NULL) return;

    // 葉節點，直接往父節點回報
    if (node->left == NULL && node->right == NULL) {
      parentMap[1] = 1;
      return;
    }
    
    // Map[ 距離 ] = 個數
    unordered_map<int, int> leftMap;
    unordered_map<int, int> rightMap;
    helper(node->left, leftMap);
    helper(node->right, rightMap);

    for (const pair<int, int>& p1 : leftMap) {
      for (const pair<int, int>& p2 : rightMap) {
        if (p1.first + p2.first > distance) continue;

        result += p1.second * p2.second;
      }
    }

    // 往父節點回報，距離 +1，個數不變
    if (node == root) return;
    for (const pair<int, int>& p1 : leftMap) {
      // 累積距離已經超過目標距離了
      // 不可能形成組合，可以刪去
      if (p1.first >= distance - 1) continue;
      parentMap[p1.first + 1] += p1.second;
    }
    for (const pair<int, int>& p2 : rightMap) {
      if (p2.first >= distance - 1) continue;
      parentMap[p2.first + 1] += p2.second;
    }
  }
};