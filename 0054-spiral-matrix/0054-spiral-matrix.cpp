// TC- O(m*n)
// SC- O(1)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int left=0;
        int up=0;
        int down = matrix.size()-1;
        int right=matrix[0].size()-1;

        while(ans.size()<(matrix.size()*matrix[0].size())){
            for(int col=left; col<=right; col++){
                ans.push_back(matrix[up][col]);
            }
            for(int row=up+1; row<=down; row++){
                ans.push_back(matrix[row][right]);
            }

            // Check if it is a different row before you start traversing right->left
            if(up!=down){
                for(int col=right-1; col>=left; col--){
                    ans.push_back(matrix[down][col]);
                }
            }
            // Check if it is a different col before you start traversing down->up
            if(left!=right){
                for(int row=down-1; row>up; row--){
                    ans.push_back(matrix[row][left]);
                }
            }

            // Update limits
            left++; right--; up++; down--;
        }
        return ans;
    }
};