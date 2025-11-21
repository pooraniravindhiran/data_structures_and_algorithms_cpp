// TC- O(n)
// SC- O(n)

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


// diamter is the longest left branch+longest right branch at a node.. you check this for every node

class Solution {
private:
    int diameter = 0;
    int longest_path(TreeNode* node){
        if(!node)
            return 0;
        int lefth = longest_path(node->left);
        int righth = longest_path(node->right);
        diameter = max(diameter, lefth+righth);
        return 1+max(lefth,righth);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        longest_path(root);
        return diameter;
    }
};