// TC- O(min(m, n))
// SC- O(1)

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int i = 0;
        int j = 0;
        while(i<firstList.size() and j<secondList.size()){
            
            int lb = max(firstList[i][0], secondList[j][0]);
            int ub = min(firstList[i][1], secondList[j][1]);
            if(lb<=ub)
                res.push_back({lb, ub});

            if(secondList[j][1]>firstList[i][1])
                i++;
            else 
                j++;

        }
        return res;
    }
};