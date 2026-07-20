// TC- O(nlog(sum(wts)))
// SC- O(1)

class Solution {
public:
    bool canShip(const int min_capacity, const vector<int>& weights, const int days){
        int curr_day_load = 0, i=0;
        int num_days = 1;
        while(i<weights.size()){
            if((curr_day_load + weights[i])<=min_capacity)
                curr_day_load += weights[i];
            else{
                curr_day_load = weights[i];
                num_days++;
            }
            i++;
        }
        return num_days<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right=0;
        for(auto& wt:weights){
            right += wt;
            left = max(left, wt);
        }

        while(left<right){
            int mid = left+(right-left)/2;
            if(canShip(mid, weights, days))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
};