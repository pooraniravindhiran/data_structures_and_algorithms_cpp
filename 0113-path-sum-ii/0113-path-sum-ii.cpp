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

// TC- O(N + NH) = O(NH) where O(N) is for DFS and O(NH) is for copying all valid paths. copying one path is O(H) and there could be N/2 leaves.
// SC- O(H+H) = O(H) where H is max height of tree

class Solution {
private:
    vector<vector<int>> result;
    void recursive_helper(TreeNode* node, int target, vector<int>& curr_path){
        if(!node)
            return;
        curr_path.push_back(node->val);
        if(!node->left && !node->right && target==node->val)
            result.push_back(curr_path);
        recursive_helper(node->left, target-node->val, curr_path);
        recursive_helper(node->right, target-node->val, curr_path);
        curr_path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return result;
        vector<int> curr_path;
        recursive_helper(root, targetSum, curr_path);
        return result;
    }
};