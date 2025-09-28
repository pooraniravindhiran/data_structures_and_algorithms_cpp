class Solution {
private:
    bool hascycle(vector<vector<int>> &adj, vector<int> &state, int n, int parent){
        if(state[n]==1)
            return true;
        
        state[n]=1;
        for(int i=0; i<adj[n].size(); i++){
            if(adj[n][i]==parent)
                continue;
            if(hascycle(adj, state, adj[n][i], n))
                return true;
        }
        state[n]=2;
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
        vector<int>  state(n, 0);
        int component = 0;

        // dfs
        for(int i=0; i<n; i++){
            if(state[i]!=2){
                component++;
                if(component>1)
                    return false;
                if(hascycle(adj, state, i, -1))
                    return false;
            }
        }
        return true;
    }
};