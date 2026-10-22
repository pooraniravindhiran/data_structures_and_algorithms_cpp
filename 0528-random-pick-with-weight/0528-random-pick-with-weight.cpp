#include <random>

class Solution {
public:
    vector<int> cum_sum;
    mt19937 gen;
    uniform_int_distribution<int> distrib;

    Solution(vector<int>& w) : gen(random_device{}()),
          distrib(1, accumulate(w.begin(), w.end(), 0)){
        // TC- O(n)
        cum_sum.assign(w.size(), 0);
        cum_sum[0] = w[0];
        for(int i=1; i<w.size(); i++)
            cum_sum[i] += cum_sum[i-1]+w[i];
    }
    
    int pickIndex() {
        // TC- O(logn)
        // pick random number
        int i = distrib(gen);

        // find 1st index >= i
        int left = 0; 
        int right = cum_sum.size()-1;
        while(left<right){
            int mid = left+(right-left)/2;

            if(cum_sum[mid]<i)
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