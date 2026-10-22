class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0, up = 0, right = n-1, down = m-1;

        while(ans.size()<(m*n)){
            for(int j=left; j<=right; j++)
                ans.push_back(matrix[up][j]);
            up++;

            for(int j=up; j<=down; j++)
                ans.push_back(matrix[j][right]);
            right--;

            if(up<=down){
                for(int j=right; j>=left; j--)
                    ans.push_back(matrix[down][j]);
                down--;
            }

            if(left<=right){
                for(int j=down; j>=up; j--)
                    ans.push_back(matrix[j][left]);
                left++;
            }
        
        }
        return ans;
    }
};