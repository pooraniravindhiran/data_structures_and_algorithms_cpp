class NumMatrix {
public:
    vector<vector<int>> sat;
    
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row==0)
            return;
        int col = matrix[0].size();
        sat = vector<vector<int>>(row+1, vector<int>(col+1));

        for(int i=1; i<=row; i++){
            for(int j=1; j<=col; j++)
                sat[i][j] = sat[i-1][j]+ sat[i][j-1]- sat[i-1][j-1]+ matrix[i-1][j-1];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(sat.size()>0)
            return sat[row2+1][col2+1]+ sat[row1][col1]- sat[row2+1][col1]- sat[row1][col2+1];
        return 0;    
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */