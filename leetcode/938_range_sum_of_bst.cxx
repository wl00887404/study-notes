#include <iostream>

#include "TreeNode.cxx"
using namespace std;

class Solution {
public:
    int low;
    int high;
    int result = 0;

    int rangeSumBST(TreeNode* root, int low, int high) {
        this->low = low;
        this->high = high;

        inorder(root);
        return result;
    }

    void inorder(TreeNode* node) {
        if (node == nullptr) return;

        if (node->val > low) inorder(node->left);

        if (low <= node->val && node->val <= high) {
            result += node->val;
        }

        if (node->val < high) inorder(node->right);
    }
};
