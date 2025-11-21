// TC - O(NH)
// SC- O(H)

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
class Solution {
private:
    void dfs_helper(TreeNode* root, int targetSum, vector<vector<int>>& result, vector<int>& curr){
        if(!root)
            return;
        curr.push_back(root->val);
        if(root->val==targetSum and !root->left and !root->right)
            result.push_back(curr);
        dfs_helper(root->left, targetSum-root->val, result, curr);
        dfs_helper(root->right, targetSum-root->val, result, curr);
        curr.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> curr;
        dfs_helper(root, targetSum, result, curr);
        return result;
    }
};