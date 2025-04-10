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
// TC- O(n) where n is number of nodes
// SC- O(n)

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            vector<int> nodes;
            while(len){
                TreeNode* node = q.front();
                q.pop();
                len--;
                if(node){
                    nodes.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if (nodes.size()>0)
                result.push_back(nodes);
        }
        return result;
    }
};