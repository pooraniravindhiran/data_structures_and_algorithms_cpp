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

// TC - O(n) where n is the number of nodes
// SC - O(w) where w is the max width of the tree

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxsum = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        int result;
        int currlevel = 1;
        while(!q.empty()){
            int levelsize = q.size();
            int levelsum = 0;
            for(int i=0; i<levelsize; i++){
                TreeNode* curr = q.front();
                q.pop();
                levelsum += curr->val;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            if(levelsum>maxsum){
                maxsum = levelsum;
                result = currlevel;
            }
            currlevel++;
        }
        return result;
    }
};