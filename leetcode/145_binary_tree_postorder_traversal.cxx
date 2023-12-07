/**
 * TODO: Format code
 */

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int> result;

        helper(root, result);

        return result;
    }

    void helper(TreeNode* node, vector<int>& result){
        if(node == nullptr) return;

        helper(node->left, result);
        helper(node->right, result);
        result.push_back(node->val);
    }
};