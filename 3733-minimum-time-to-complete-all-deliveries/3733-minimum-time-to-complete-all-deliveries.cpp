// TC- log((d1+d2)*max(r1, r2))
// SC- O(1)

class Solution {
private:
    bool canDeliver(long long time, vector<int>& d, vector<int>& r){
        long long capacity_1 = min((long long)d[0], time-time/r[0]);
        long long capacity_2 = min((long long)d[1], time-time/r[1]);

        long long g = gcd(r[0], r[1]);
        long long timeint_both_charge = (1LL * r[0] * r[1]) / g;// lcm
        long long usable_time = time - (time / timeint_both_charge);

        long long total = (1LL* d[0])+d[1];
        return (total<=usable_time) and ((capacity_1+capacity_2)>=(d[0]+d[1]));
    }
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long left = 0;
        long long right = ((1LL*d[0])+d[1])*max(r[0], r[1]); // actual is d1+d2+(d1/r1)+(d2/r2), but we cant find a guaranteed upper bound due to /, so pick a guaranteed bound even if loose

        // binary search on ans space
        while(left<right){
            long long mid = left+(right-left)/2;
            if(canDeliver(mid, d, r))
                right = mid;
            else
                left = mid+1;
        }
        return left;

    }
};