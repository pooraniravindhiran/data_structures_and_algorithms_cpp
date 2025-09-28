// tc- O(e+n)
// sc- O(e+n)

class Solution {
private:
    unordered_set<int> visited;
    void dfs_helper(vector<vector<int>>& adjlist, int i){
        visited.insert(i);
        for(auto& n:adjlist[i]){
            if(visited.find(n)==visited.end())
                dfs_helper(adjlist, n);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans=0;

        // create adj matrix
        vector<vector<int>> adjlist(n);
        for(auto edge:edges){
            adjlist[edge[0]].push_back(edge[1]);
            adjlist[edge[1]].push_back(edge[0]);
        }

        for(int i=0; i<n; i++){
            if(visited.find(i)==visited.end()){
                ans++;
                dfs_helper(adjlist, i);
            }
        }
        return ans;
    }
};