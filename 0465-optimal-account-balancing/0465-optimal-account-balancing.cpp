// TC- O(t+p!)
// SC- O(p)

class Solution {
private:
    int dfs(vector<int>& balance, int start){
        // skip settled people
        while(start<balance.size() and balance[start]==0)
            start++;
        
        // settled is at end
        if(start==balance.size())
            return 0;
            
        int ans = INT_MAX;
        for(int i=start+1; i<balance.size(); i++){
            if((balance[i]*balance[start])<0){
                balance[i] += balance[start];
                int num_transactions = 1+dfs(balance, start+1);
                ans = min(ans, num_transactions);
                balance[i] -= balance[start];

                // pruning
                if(balance[i]+balance[start]==0)
                    break;
            }
        }
        return ans;
    }

public:
    int minTransfers(vector<vector<int>>& transactions) {
        // not graph problem once you find net balance, find it first
        unordered_map<int, int> balance;
        for(int i=0; i<transactions.size(); i++){
            int from = transactions[i][0];
            int to = transactions[i][1];
            int amt = transactions[i][2];

            balance[from] -= amt;
            balance[to] += amt;
        }
        vector<int> net_balance;
        for(auto& [person, amt]:balance){
            if(amt!=0)
                net_balance.push_back(amt);
        }

        // given net_balance, all you need to do is backtrack to find min num of required transactions so that everyone is settled
        return dfs(net_balance, 0);
    }
};