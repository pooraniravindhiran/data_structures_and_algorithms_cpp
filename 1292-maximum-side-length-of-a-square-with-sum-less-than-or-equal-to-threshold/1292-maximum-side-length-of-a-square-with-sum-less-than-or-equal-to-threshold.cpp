// TC- O(log(min(m, n))* mn* (mid^2))
// SC- O(1)

// class Solution {
// private:
//     bool squareExists(const int& m, const int& n, const int& mid, const vector< vector<int>>& mat, const int& threshold){
//         for(int i=0; i<(m-mid)+1; i++){
//             for(int j=0; j<(n-mid)+1; j++){
//                 int sum = 0;
//                 for(int row=i; row<i+mid; row++){
//                     for(int col=j; col<j+mid; col++){
//                         sum += mat[row][col];
//                     }
//                 }
//                 if(sum<=threshold)
//                     return true;
//             }
//         }
//         return false;
//     }
// public:
//     int maxSideLength(vector<vector<int>>& mat, int threshold) {
//         int m = mat.size(), n = mat[0].size();
//         int left = 0, right = min(m, n);

//         while(left<right){
//             int mid = left+ (right-left+1)/2;

//             if(squareExists(m, n, mid, mat, threshold))
//                 left = mid;
//             else
//                 right = mid-1;
//         }
//         return left;
//     }
// };

// TC- O(log(min(m, n))*mn)
// SC- O(mn)

class Solution {
private:
    bool squareExists(const int& m, const int& n, const int& mid, const vector< vector<int>>& prefix_sum, const int& threshold){
        for(int i=0; i<(m-mid)+1; i++){
            for(int j=0; j<(n-mid)+1; j++){
                // from i to i+mid-1 and j to j+mid-1
                int sum = prefix_sum[i+mid][j+mid] - prefix_sum[i][j+mid]- prefix_sum[i+mid][j] +prefix_sum[i][j];
                if(sum<=threshold)
                    return true;
            }
        }
        return false;
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        int left = 0, right = min(m, n);

        // compute prefix sum
        vector<vector<int>> prefix_sum(m+1, vector<int>(n+1, 0));
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++)
                prefix_sum[i][j] = mat[i-1][j-1] + prefix_sum[i-1][j] +prefix_sum[i][j-1] -prefix_sum[i-1][j-1];
        }

        while(left<right){
            int mid = left+ (right-left+1)/2;

            if(squareExists(m, n, mid, prefix_sum, threshold))
                left = mid;
            else
                right = mid-1;
        }
        return left;
    }
};

     
