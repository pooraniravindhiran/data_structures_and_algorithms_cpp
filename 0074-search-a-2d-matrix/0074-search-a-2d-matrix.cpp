// TC- O(log(mn))
// SC- O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // 2d matrix can be treated as a 1d sorted array here and all we need to do is binary search. given idx in array, the corresponding row = idx/cols, col = idx%cols;
        int left = 0;
        int right = rows*cols-1;
        while(left<=right){
            int mid = left+ ((right-left)/2);
            int r = mid/cols;
            int c= mid%cols;
            if(matrix[r][c]==target)
                return true;
            else if(matrix[r][c]<target)
                left++;
            else
                right--;
        }
        return false;
    }
};