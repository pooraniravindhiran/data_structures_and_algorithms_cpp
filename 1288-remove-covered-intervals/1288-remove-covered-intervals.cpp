// TC- O(nlogn)
// SC- O(logn)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // sort intervals by start time, but what if they start at same time, then sort by descending end interval because it covers the other
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b){
                if(a[0]==b[0])
                    return a[1]>b[1];
                return a[0]<b[0];
        });
        
        int max_end = intervals[0][1];
        int uncovered = 1;
        for(int i=1; i<intervals.size(); i++){
            if(max_end<intervals[i][1])
                uncovered++;
            max_end = max(intervals[i][1], max_end);
        }
        return uncovered;
    }
};