// TC- O(v+e)
// SC- O(e+v)

class Solution {
private:
    bool hascycle(vector<vector<int>> &adj, unordered_set<int>& visited, int n, int parent){
        
        visited.insert(n);
        for(int neigh : adj[n]) {
            if(neigh == parent)
                continue;

            if(visited.find(neigh) != visited.end())
                return true;

            if(hascycle(adj, visited, neigh, n))
                return true;
    }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        //create adj list
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // create list for visit state for detecting cycle and int for components
        unordered_set<int> visited;
        int component = 0;

        // dfs
        for(int i=0; i<n; i++){
            if(visited.find(i)==visited.end()){
                component++;
                if(component>1)
                    return false;
                if(hascycle(adj, visited, i, -1))
                    return false;
            }
        }
        return true;
    }
};