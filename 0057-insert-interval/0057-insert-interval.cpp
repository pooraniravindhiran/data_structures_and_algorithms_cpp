// TC- O(n)
// SC- O(1)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        // case 1: intervals that are non-overlapping and before newInterval
        int i=0;
        while(i<intervals.size() and intervals[i][1]<newInterval[0])
            ans.push_back(intervals[i++]);

        // case 2: intervals that are overlapping with newInterval
        while(i<intervals.size() and intervals[i][0]<=newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);

        // case 3: intervals that are non-overlapping and after newInterval
        while(i<intervals.size())
            ans.push_back(intervals[i++]);
        return ans;
    }
};