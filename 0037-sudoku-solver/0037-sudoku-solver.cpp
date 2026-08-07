// TC- O(9^e)
// SC- O(e) where e is number of empty cells

class Solution {
private:
    vector<vector<int>> rows, cols, boxes;
    bool solved = false;

    void remove(int d, int r, int c, vector<vector<char>>& board){
        board[r][c] = '.';
        rows[r][d]--;
        cols[c][d]--;
        int b = (r/3)*3+(c/3);
        boxes[b][d]--;
    }

    bool canplace(int d, int r, int c){
        int b = (r/3)*3+(c/3);
        return rows[r][d]==0 and cols[c][d]==0 and boxes[b][d]==0;
    }

    void place(int d, int r, int c, vector<vector<char>>& board){
        board[r][c] = d+'0';
        rows[r][d]++;
        cols[c][d]++;
        int b = (r/3)*3+(c/3);
        boxes[b][d]++;
    }

    void nextcell(int r, int c, vector<vector<char>>& board){
        if(r==8 and c==8){
            solved= true;
            return;
        }

        else if(c==8)
            backtrack(r+1, 0, board);
        else
            backtrack(r, c+1, board);
    }

    void backtrack(int r, int c, vector<vector<char>>& board){
        if(board[r][c]!='.'){
            nextcell(r, c, board);
            return;
        }
        else{
            for(int d=1; d<=9; d++){
                if(!canplace(d, r, c))
                    continue;
                place(d, r, c, board);
                nextcell(r, c, board);
                if(!solved)
                    remove(d, r, c, board);
            }
        }
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        rows.assign(9, vector<int>(10, 0));
        cols.assign(9, vector<int>(10, 0));
        boxes.assign(9, vector<int>(10, 0));

        for(int r=0; r<9; r++){
            for(int c=0; c<9; c++){
                if(board[r][c]!='.'){
                    int d = board[r][c]-'0';
                    place(d, r, c, board);
                }  
            }
        }

        backtrack(0, 0, board);
    }
};