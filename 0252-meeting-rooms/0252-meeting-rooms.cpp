// TC- O(nlogn)
// SC- O(logn)

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size()==0)
            return true;

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[0]<b[0];});
        for(int i=0; i<intervals.size()-1; i++){
            if(intervals[i+1][0]<intervals[i][1])
                return false;
        }
        return true;
    }
};