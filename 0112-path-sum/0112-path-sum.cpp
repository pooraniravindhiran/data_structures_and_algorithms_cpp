/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// TC- O(n)
// SC- O(h)

class Solution {
private:
    bool recursive_helper(TreeNode* node, int target){
        if(!node)
            return false;
        else if(!node->left && !node->right && target==node->val)
            return true;
        else
            return (recursive_helper(node->left, target-node->val) or recursive_helper(node->right, target-node->val));
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        return recursive_helper(root, targetSum);
    }
};