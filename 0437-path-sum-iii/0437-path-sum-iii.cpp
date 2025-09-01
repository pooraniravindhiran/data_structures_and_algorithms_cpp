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
// TC- O(NH)
// SC- O(H)

class Solution {
private:
    int recursive_helper(TreeNode* node, long long target){
        if(!node)
            return 0;
        int count = 0;
        if(node->val==target)
            count++;
        count += recursive_helper(node->left, target-node->val);
        count += recursive_helper(node->right, target-node->val);
        return count;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return 0;

        int count = recursive_helper(root, (long long) targetSum);

        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);

        return count;
    }
};