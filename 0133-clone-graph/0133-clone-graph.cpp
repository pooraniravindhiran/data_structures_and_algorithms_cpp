/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// TC- O(n+e) where n is number of nodes and e is number of edges
// SC- O(n)

class Solution {
private:
    unordered_map<Node*, Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return node;
        Node* curr = new Node(node->val);
        if(visited.find(node)!=visited.end())
            return visited[node];
        else{
            visited.insert(make_pair(node, curr));
            for(int i=0; i<node->neighbors.size(); i++){
                Node* neigh = cloneGraph(node->neighbors[i]);
                curr->neighbors.push_back(neigh);
            }
        }  
        return curr;
    }
};