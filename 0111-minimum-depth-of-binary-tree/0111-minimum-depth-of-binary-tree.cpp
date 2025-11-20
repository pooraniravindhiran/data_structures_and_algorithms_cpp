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
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 1);
        while(!q.empty()){
            int len = q.size();
            for(int i=0; i<len; i++){
                auto [node, depth] = q.front();
                q.pop();

                // stops after finding first leaf
                if(!node->left and !node->right)
                    return depth;

                if(node->left)
                    q.emplace(node->left, depth+1);
                if(node->right)
                    q.emplace(node->right, depth+1);
            }
        }
        return 0;
    }
};