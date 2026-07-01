// TC- O(mn)
// SC- O(1)

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> valid;
        valid.assign(10, false);

        for(int i=0; i<board.size(); i++){
            valid.assign(10, false);
            for(int j=0; j<board[0].size(); j++){
                if (board[i][j]!= '.'){
                    int num = board[i][j]-'0';
                    // cout<<num<<endl;
                    if (valid[num] == true)
                        return false;
                    valid[num] = true;
                }
            }
        }

        for(int j=0; j<board[0].size(); j++){
            valid.assign(10, false);
            for(int i=0; i<board.size(); i++){
                if (board[i][j]!= '.'){
                    int num = board[i][j]-'0';
                    // cout<<num<<endl;
                    if (valid[num] == true)
                        return false;
                    valid[num] = true;
                }
            }
        }

        for(int i=0; i<9; i++){
            valid.assign(10, false);
            int startRow = (i/3)*3;
            int startCol = (i%3)*3;
            for(int j=0; j<9; j++){
                int r = (j/3) + startRow;
                int c = (j%3) + startCol;
                if (board[r][c]!= '.'){
                    int num = board[r][c]-'0';
                    // cout<<num<<endl;
                    if (valid[num] == true)
                        return false;
                    valid[num] = true;
                }
            }
        }

        return true;
    }
};