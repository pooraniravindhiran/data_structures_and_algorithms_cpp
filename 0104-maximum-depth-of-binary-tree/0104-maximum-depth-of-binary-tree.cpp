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
// SC- O(n) (best case- balanced tree- O(logn))

class Solution {
    int rBFS(TreeNode* node, int level){
        if(node==NULL)
            return level-1;
        return max(rBFS(node->left, level+1), rBFS(node->right, level+1));
    }
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        return rBFS(root, 1);
    }
};



























//  Top down approach
// class Solution {
//     int ans=0;
//     void helper(TreeNode* node, int depth){
//         if(node==NULL)
//             return;
//         if(node->left==NULL and node->right==NULL)
//             ans= max(ans, depth);
//         helper(node->left,depth+1);
//         helper(node->right, depth+1);
//     }
// public:
//     int maxDepth(TreeNode* root) {
//         helper(root, 1);
//         return ans;
//     }
// };

//bottom up approach
// class Solution {
//     int helper(TreeNode* node){
//         if(node==NULL)
//             return 0;
//         return max(helper(node->left), helper(node->right))+1;
//     }
// public:
//     int maxDepth(TreeNode* root) {
//         return helper(root);
//     }
// };