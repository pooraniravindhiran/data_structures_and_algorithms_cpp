class NumMatrix {
private:
    int m, n;
    vector<vector<int>> summed;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n= matrix[0].size();

        vector<vector<int>> summed(m+1, vector<int>(n+1,0));

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                summed[i+1][j+1] = summed[i+1][j]+summed[i][j+1]-summed[i][j]+matrix[i][j];
            }
        }
        this->summed = summed;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // TC- O(1)
        // SC- O(1)
        return summed[row2+1][col2+1]-summed[row1][col2+1]-summed[row2+1][col1]+summed[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */