// TC- O(n)
// SC- O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_p = 0;
        int curr_b = prices[0];
        for(int i=1; i<prices.size();i++){
            if(prices[i]<curr_b)
                curr_b = prices[i];
            if(prices[i]>curr_b)
                max_p = max(max_p, prices[i]-curr_b);
        }
        return max_p;
    }
};