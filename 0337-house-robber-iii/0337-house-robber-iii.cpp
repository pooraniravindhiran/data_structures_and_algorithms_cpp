// TC - O(n)
// SC - O(n)

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
    pair<int,int> postorder_helper(TreeNode* node){
        if(!node)
            return make_pair(0,0);

        auto left = postorder_helper(node->left);
        auto right = postorder_helper(node->right);
        int skipped = max(left.first, left.second) + max(right.first, right.second);
        int not_skipped = node->val+right.second+left.second;
        return make_pair(not_skipped, skipped);
    }
public:
    int rob(TreeNode* root) {
        // if node is robbed, its children cant be.
        // for every node, you get 2 values- max if it was robbed and max if it was not
        auto res = postorder_helper(root);
        return max(res.first, res.second);
    }
};