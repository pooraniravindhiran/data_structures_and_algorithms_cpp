bool compareSecondElement(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int result = 0;
        sort(intervals.begin(), intervals.end(), compareSecondElement);
        int max = intervals[0][1];
        for(int i =1; i<intervals.size(); i++){
            if(intervals[i][0]>=max)
                max = intervals[i][1];
            else
                result+=1;
        }
        return result;
    }
};