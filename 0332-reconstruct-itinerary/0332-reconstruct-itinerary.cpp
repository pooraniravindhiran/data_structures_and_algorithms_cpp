// TC- O(t+tlogt+t+t)
// SC- O(t)

class Solution {
private:
    unordered_map<string, vector<string>> adj_mat;
    vector<string> res;
    void dfs(string airport){
        vector<string>& neighbors = adj_mat[airport];
        while(!neighbors.empty()){
            string first = neighbors.back();
            neighbors.pop_back();
            dfs(first);
        }
        res.push_back(airport);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // create adj matrix
        for(auto& ticket:tickets)
            adj_mat[ticket[0]].push_back(ticket[1]);
        for(auto& [src, dsts]:adj_mat)
            sort(dsts.rbegin(), dsts.rend());
        
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};