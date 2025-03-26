// TC- O(nlogn) where n is number of intervals
// SC - O(logn) for sorting
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // sort intervals because if not, then O(n^2). 
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[0]<b[0];});

        vector<vector<int>> ans;
        for(int i=0; i<intervals.size(); i++){
            int min = intervals[i][0];
            int max = intervals[i][1];
            while(i+1<intervals.size() and intervals[i+1][0]<=max){
                if(intervals[i+1][1]>max)
                    max = intervals[i+1][1];
                i++;
            }
            ans.push_back({min, max});
        }
        return ans;
    }
};