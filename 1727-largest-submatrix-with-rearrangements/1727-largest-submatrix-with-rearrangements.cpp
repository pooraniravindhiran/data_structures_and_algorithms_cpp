// tc- O(mnlogn)
// SC- O(log(n))

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]!=0)
                    matrix[i][j] += matrix[i-1][j];
            }
        }

        int max_area = 0;
        for(int i=0; i<m; i++){
            sort(matrix[i].rbegin(), matrix[i].rend());
            for(int j=0; j<n; j++){
                int ht = matrix[i][j];
                int wt = j+1;
                max_area = max(max_area, wt*ht);
            }
        }
        return max_area;
    }
};