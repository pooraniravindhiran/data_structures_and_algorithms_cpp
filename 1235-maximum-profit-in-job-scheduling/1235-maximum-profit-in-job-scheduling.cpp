class Solution {
private:
    vector<int> memo;
    vector<vector<int>> jobs;
    int n;
    int next_task(int end){
        int left =0;
        int right = n-1;
        int ans = n;
        while(left<=right){
            int mid = left+(right-left)/2;

            if (jobs[mid][0]<end)
                left = mid+1;
            else{
                ans = mid;
                right = mid-1;
            }
        }
        return ans;
    }

    int maxProfitsFrom(int i){
        if (i==n)
            return 0;

        if(memo[i]!=-1)
            return memo[i];
        
        int skip = maxProfitsFrom(i+1);
        int take = jobs[i][2]+maxProfitsFrom(next_task(jobs[i][1]));
        memo[i] = max(skip, take);
        return memo[i];
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        // sort by start time
        // if i pick a task vs i dont
        // (profits[i] + maxprofit(next_task after endtime[i]) , maxprofit(i+1)

        n = startTime.size();
        for(int i=0; i<n; i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        sort(jobs.begin(), jobs.end());

        memo.assign(n, -1);
        return maxProfitsFrom(0);
    }
};