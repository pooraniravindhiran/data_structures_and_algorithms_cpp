// SC - O(1)
// TC- O(m+n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // taking top right corner. so if target is less, you move left. else you move down.
        int r = 0;
        int c = cols-1;

        while(r>=0 and r<rows and c>=0 and c<cols){
            if(matrix[r][c]==target)
                return true;
            else if(matrix[r][c]<target)
                r++;
            else if(matrix[r][c]>target)
                c--;
        }
        return false;
    }
};