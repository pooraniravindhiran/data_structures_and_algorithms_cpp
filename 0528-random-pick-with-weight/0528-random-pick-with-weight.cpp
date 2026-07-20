// SC- O(n)

class Solution {
public:
    vector<int> prefix_sum;
    Solution(vector<int>& w) {
        // TC- O(n)
        // for probability based picking, you can select weights based on prefix sum
        int ps = 0;
        for(int i=0; i<w.size(); i++){
            ps += w[i];
            prefix_sum.push_back(ps);
        }
    }
    
    int pickIndex() {
        // TC- O(logn)
        int i = rand()%prefix_sum.back() +1;
        
        // need the first pefix_sum idx >= i
        int left = 0, right = prefix_sum.size()-1;
        while(left<right){
            int mid = left+(right-left)/2;
            if(prefix_sum[mid]<i)
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */