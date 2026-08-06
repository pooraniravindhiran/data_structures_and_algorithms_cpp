// TC- O(wlogw+blogb)
// SC- O(w)

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        // compute effective capacity
        vector<int> left = warehouse;
        vector<int> right = warehouse;
        for(int i=1; i<left.size(); i++)
            left[i] = min(left[i], left[i-1]);
        for(int i=right.size()-2; i>=0; i--)
            right[i] = min(right[i], right[i+1]);
        for(int i=0; i<warehouse.size(); i++)
            warehouse[i] = max(left[i], right[i]);
        
        sort(warehouse.begin(), warehouse.end());
        sort(boxes.begin(), boxes.end());

        int j=0;
        for(int i=0; i<warehouse.size() and j<boxes.size(); i++){
            if(boxes[j]<=warehouse[i])
                j++;
        }
        return j;
    }
};