/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    TreeNode* buildTree(queue<string>& q){
        if(q.empty())
            return NULL;
        string val = q.front(); q.pop();
        if(val=="#") return NULL;
        TreeNode* curr = new TreeNode(stoi(val));
        curr->left = buildTree(q);
        curr->right = buildTree(q);
        return curr;
    }
public:

    // TC- O(n)
    // SC- O(h)
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "#";
        
        return to_string(root->val) + "," + 
            serialize(root->left) + "," +
            serialize(root->right);
    }

    // TC- O(n)
    // SC- O(n)
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="#,")
            return NULL;
        queue<string> q;
        string val;
        for(char ch:data){
            if(ch==','){
                q.push(val);
                val = "";
            }
            else
                val += ch;
        }
        return buildTree(q);   
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));