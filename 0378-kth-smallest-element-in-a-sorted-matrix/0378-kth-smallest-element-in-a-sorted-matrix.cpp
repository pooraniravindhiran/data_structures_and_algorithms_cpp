// TC- O(n * log(max-min)) where log(max-min) is the number of steps in the binary search, and n is the TC for countlessthan
// SC- O(1)

class Solution {
private:
    int countlessthan(vector<vector<int>>& matrix, int mid){
        int n = matrix.size();
        int row = n-1;
        int col = 0;
        int count = 0;

        while(row>=0 and col<n){
            if(matrix[row][col]<=mid){
                count += row+1; 
                col++;
            }
            else{
                row--;
            }
        }
        return count;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        int low = matrix[0][0];
        int high = matrix[n-1][n-1];

        while(low<high){
            int mid = low + (high-low)/2;
            int n = countlessthan(matrix, mid);
            if(n<k)
                low = mid+1;
            else
                high = mid;
        }
        return low;
    }
};