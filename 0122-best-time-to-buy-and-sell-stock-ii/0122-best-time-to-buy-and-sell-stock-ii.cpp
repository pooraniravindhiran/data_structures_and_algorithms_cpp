// TC- O(n)
// SC- O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;

        // ideally you need to find sum of diff between every valley and its immediate peak. Immediate peak will always be best because c<a+b. 
        for(int i=1; i<prices.size(); i++){
            if(prices[i]>prices[i-1]){
                ans += prices[i]-prices[i-1];
            }
        }
        return ans;

    }
};