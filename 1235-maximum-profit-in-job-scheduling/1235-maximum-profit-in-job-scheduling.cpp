// TC- O(nlogn)
// SC- O(n)

class Solution {
private:
    vector<int> dp;
    int n;
    vector<vector<int>> jobs;

    int find_next(int t){
        int left= 0, right=n-1;
        int ans = n;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(jobs[mid][0]<t)
                left = mid+1;
            else{
                ans = mid;
                right = mid-1;
            }
        }
        return ans;
    }

    int max_profits_from(int i){
        if(i>=n)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        dp[i] = max(jobs[i][2]+max_profits_from(find_next(jobs[i][1])), max_profits_from(i+1));
        return dp[i];
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = profit.size();
        for(int i=0; i<n; i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        sort(jobs.begin(), jobs.end());
        dp.assign(n, -1);
        return max_profits_from(0);
    }
};