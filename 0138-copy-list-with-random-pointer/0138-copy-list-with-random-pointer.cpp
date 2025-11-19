// TC- O(n)
// SC - O(n)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> visited;
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return head;
        
        if(visited.count(head))
            return visited[head];
        
        Node* curr = new Node(head->val, NULL, NULL);
        visited[head] = curr;
        curr->next = copyRandomList(head->next);
        curr->random = copyRandomList(head->random);
        return curr;
    }
};