class Solution {
private:
    long long total = 0;
    long long min_ele = INT_MAX;
    int num_neg_ele = 0;
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]<0)
                    num_neg_ele++;
                total += abs(matrix[i][j]);
                if(abs(matrix[i][j])<min_ele)
                    min_ele = abs(matrix[i][j]);
            }
        }

        return (num_neg_ele%2) ? total - (2*min_ele): total;
    }
};