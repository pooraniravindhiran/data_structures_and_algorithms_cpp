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
// SC- O(w)

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(!root)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int levelsize = q.size();
            for(int i=0; i<levelsize; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(i==0)
                    result.push_back(curr->val);
                if(curr->right)
                    q.push(curr->right);
                if(curr->left)
                    q.push(curr->left);  
            }
        }
        return result;
    }
};