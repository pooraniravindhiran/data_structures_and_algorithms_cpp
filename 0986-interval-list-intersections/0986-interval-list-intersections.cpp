// TC- O(min(m,n))
// SC- O(1)

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i=0, j=0;
        vector<vector<int>> result;

        while(i<firstList.size() and j<secondList.size()){
            // starting of the intersection
            int low = max(firstList[i][0], secondList[j][0]);

            // ending of the intersection
            int high = min(firstList[i][1], secondList[j][1]);

            if(low<=high)
                result.push_back({low, high});
            
            if(firstList[i][1]<secondList[j][1])
                i++;
            else
                j++;
        }

        return result;
    }
};