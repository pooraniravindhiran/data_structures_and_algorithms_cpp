// TC- O(eloge + n*a(e)) where n is total number of email occurrences
// SC- O(e) where e is num of unique emails

class UnionFind{
public:
    vector<int> parent, rank;

    UnionFind(int n){
        parent.resize(n);
        for(int i=0; i<parent.size(); i++)
            parent[i] = i;
        rank.resize(n, 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        // Union by rank
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Solution {
private:
    unordered_map<string, string> email_to_name;
    unordered_map<string, int> email_to_id;
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int i = 0;
        for(auto& account:accounts){
            string& name = account[0];
            for (int j = 1; j < account.size(); j++) {
                string email = account[j];
                if(email_to_id.find(email)==email_to_id.end()){
                    email_to_id[email] = i++;
                    email_to_name[email] = name;
                }
            }
        }

        UnionFind uf (i);

        for(auto& account:accounts){
            string& name = account[0];
            string first_email = account[1];
            for (int j = 2; j < account.size(); j++) {
                string email = account[j];
                uf.unite(email_to_id[first_email], email_to_id[email]);
            }
        }
        
        // group emails
        unordered_map<int, vector<string>> groups;
        for (auto& [email, emailId] : email_to_id) {
            groups[uf.find(emailId)].push_back(email);
        }

        vector<vector<string>> ans;
        for(auto& [id, emails]:groups){
            string name = email_to_name[emails[0]];
            vector<string> merged;
            merged.push_back(name);
            sort(emails.begin(), emails.end());
            for (auto& email : emails)
                merged.push_back(email);
            ans.push_back(merged);
        }

        return ans;
    }
};