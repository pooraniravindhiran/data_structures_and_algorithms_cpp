// TC- O(m*n)
// SC- O(1)

class Solution {
private:
    void transpose(vector<vector<int>>& matrix){
        for(int i=0; i<matrix.size(); i++){
            for(int j=i+1; j<matrix[0].size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    void reverse(vector<vector<int>>& matrix){
        for(int r=0; r<matrix.size(); r++){
            for(int i=0, j=matrix[0].size()-1; i<j; i++, j--){
                swap(matrix[r][i], matrix[r][j]);
            }
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverse(matrix);
    }
};