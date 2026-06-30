// TC- O(min(m, n))
// SC-

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;

        int i = 0;
        int j = 0;

        while(i<firstList.size() and j<secondList.size()){
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);
            if (start<=end)
                ans.push_back({start, end});

            if (firstList[i][1]<secondList[j][1])
                i += 1;
            else if (firstList[i][1]>=secondList[j][1])
                j += 1;
        }
        return ans;
    }
};