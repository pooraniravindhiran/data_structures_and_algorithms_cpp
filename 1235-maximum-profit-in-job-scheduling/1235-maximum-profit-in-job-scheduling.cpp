class Solution {
private:
    int n;
    vector<vector<int>> jobs;
    vector<int> dp;

    int find_next(int i){
        // bs on start time to find the val>=i

        int left = 0;
        int right = n;

        while(left<right){
            int mid = left+(right-left)/2;

            if(jobs[mid][0]<i)
                left = mid+1;
            
            else
                right = mid;
        }
        return left;
    }

    int max_profits_from(int i){
        if(i>=n)
            return 0;
        
        if (dp[i] != -1)
            return dp[i];

        // i can be included
        int include = jobs[i][2] + max_profits_from(find_next(jobs[i][1]));

        // i cant be included
        int skip = max_profits_from(i+1);

        dp[i] = max(include, skip);
        return dp[i];
    }

    
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        for(int i=0; i<startTime.size(); i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        sort(jobs.begin(), jobs.end());
        dp.assign(n, -1);
        return max_profits_from(0);
    }
};