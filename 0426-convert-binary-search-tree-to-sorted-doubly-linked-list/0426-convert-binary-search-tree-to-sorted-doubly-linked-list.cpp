// TC- O(n)
// SC- O(n)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
private:
    Node* first = NULL;
    Node* last = NULL;
    void inorder(Node* node){
        if(!node)
            return;
        
        inorder(node->left);
        if(last){
            last->right = node;
            node->left = last;
        }
        else
            first = node;
        last = node;
        inorder(node->right);
    }
public:
    Node* treeToDoublyList(Node* root) {
        if(root==NULL)
            return root;
        
        inorder(root);
        first->left = last;
        last->right = first;
        return first;
    }
};