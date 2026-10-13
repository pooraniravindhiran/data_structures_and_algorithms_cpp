class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int nrows = 9;
        int ncols = 9;

        for(int i=0; i<nrows; i++){
            vector<bool> digits(9, false);
            for(int j=0; j<ncols; j++){
                if(board[i][j]=='.')
                    continue;
                if(digits[board[i][j]-'1']==true)
                    return false;
                digits[board[i][j]-'1'] = true;
            }
        }

        for(int j=0; j<ncols; j++){
            vector<bool> digits(9, false);
            for(int i=0; i<nrows; i++){
                if(board[i][j]=='.')
                    continue;
                if(digits[board[i][j]-'1']==true)
                    return false;
                digits[board[i][j]-'1'] = true;
            }
        }

        for(int i=0; i<nrows; i++){
            int start_r = (i/3)*3;
            int start_c = (i%3)*3;
            // cout<<start_r<<" "<<start_c<<endl;
            vector<bool> digits(9, false);
            for(int j=0; j<nrows; j++){
                int r = (j/3)+start_r;
                int c = (j%3)+start_c;
                // cout<<r<<" "<<c<<endl;
                if(board[r][c]=='.')
                    continue;
                if(digits[board[r][c]-'1']==true)
                    return false;
                digits[board[r][c]-'1'] = true;
            }
        }
        return true;

    }
};