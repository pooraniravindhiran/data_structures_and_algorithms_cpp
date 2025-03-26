// TC- O(nlogn)
// SC - O(logn)

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort based on end times- we need min number of overlapping intervals - i.e max number of non overalpping intervals- this means given 2 end times, we should also retain one with smaller end time. 
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int>b){return a[1]<b[1];});

        // decide if current interval is overlapping with most recent end time stored. if not, then update end time. If so, then update ans.
        int ans = 0; int end = INT_MIN;
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][0] >= end)
                end = intervals[i][1];
            else
                ans++;
        }
        return ans;
    }
};