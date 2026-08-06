// TC- O(w+blogb)
// SC- O(1)

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        // compute effective height of rooms
        for(int i=1; i<warehouse.size(); i++)
            warehouse[i] = min(warehouse[i], warehouse[i-1]);

        // sort boxes because
        sort(boxes.begin(), boxes.end());

        int j=0;
        for(int i=warehouse.size()-1; i>=0 and j<boxes.size(); i--){
            if(boxes[j]<=warehouse[i])
                j++;
        }
        return j;
    }
};