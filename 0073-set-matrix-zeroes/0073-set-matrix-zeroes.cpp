// TC- O(m*n)
// SC - O(1)

class Solution {
private:
    bool isfirstcolzero = false;
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // flag first cell of corresponding row and column
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    if(j==0)
                        isfirstcolzero = true;
                    else {
                        matrix[i][0]=0;
                        matrix[0][j]=0;
                    }
                }
            }
        }

        // check for set flags in all rows and cols except first
        for(int i=1; i<matrix.size(); i++){
            for(int j=1; j<matrix[0].size(); j++){
                if(matrix[i][0]==0 or matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }

        // check flag for first row before checking col to avoid override
        if(matrix[0][0]==0){
            for(int j=1; j<matrix[0].size(); j++){
                matrix[0][j]=0;
            }
        }

        if(isfirstcolzero){
            for(int i=0; i<matrix.size(); i++){
                matrix[i][0]=0;
            }
        }
    }
};