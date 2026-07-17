// TC- O(nlogn) where n is num of unique emails
// SC- O(n)

class Solution {
public:
    void dfs(const string& email, unordered_set<string>& visited, unordered_map<string, vector<string>>& adj_mat, vector<string>& connected){
            visited.insert(email);
            connected.push_back(email);

            for(string& neigh:adj_mat[email]){
                if(visited.find(neigh)==visited.end())
                    dfs(neigh, visited, adj_mat, connected);
            }
        }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailstoname;
        unordered_map<string, vector<string>> adjmat;

        for(auto& account:accounts){
            string name = account[0];
            string firstemail = account[1];
            
            for(int i=1; i<account.size(); i++){
                string email = account[i];
                emailstoname[email] = name;
                adjmat[email].push_back(firstemail);
                adjmat[firstemail].push_back(email);
            }
        }

        vector<vector<string>> res;
        unordered_set<string> visited;
        for(auto& [email, name]:emailstoname){
            if(visited.find(email)==visited.end()){
                vector<string> connected;
                dfs(email, visited, adjmat, connected);
                sort(connected.begin(), connected.end());
                connected.insert(connected.begin(), emailstoname[email]);
                res.push_back(connected);
            }
        }
        return res;
    }
};