// SC - O(2^d) where d is depth of tree O(2^d) = O(n) as n = (2^d+1)-1
// TC - O(n) where n is num of nodes in tree

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        bool lefttoright = false;
        while(!q.empty()){
            int len = q.size();
            vector<int> curr_level(len);
            lefttoright ^= true;
            int index;
            for(int i=0; i<len; i++){
                TreeNode* curr = q.front();
                q.pop();
                index = lefttoright ? i:len-i-1;
                curr_level[index]= curr->val;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            result.push_back(curr_level);
        }

        return result;
    }
};