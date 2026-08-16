// TC- O(1)
// SC- O(1)

class Solution {
private:
    vector<vector<int>> rows, cols, boxes;
    bool is_solved = false;

    void place(int d, int r, int c, vector<vector<char>>& board){
        board[r][c] = d+'0';
        rows[r][d] = 1;
        cols[c][d] = 1;
        int b = (r/3)*3+(c/3);
        boxes[b][d] = 1;
    }

    void remove(int d, int r, int c, vector<vector<char>>& board){
        board[r][c] = '.';
        rows[r][d] = 0;
        cols[c][d] = 0;
        int b = (r/3)*3+(c/3);
        boxes[b][d] = 0;
    }

    bool can_place(int d, int r, int c){
        int b= (r/3)*3+(c/3);
        return rows[r][d]==0 and cols[c][d]==0 and boxes[b][d]==0;
    }

    void backtrack(int r, int c, vector<vector<char>>& board){
        // check if end then solved return
        if(r==9){
            is_solved = true;
            return;
        }

        // find next cell and keep
        int nr = r;
        int nc = c+1;
        if(nc==9){
            nr = nr+1;
            nc = 0;
        }

        // if number, goto next cell
        if(board[r][c]!='.')
            backtrack(nr, nc, board);

        // if empty, place backtrack
        else{
            for(int i=1; i<10; i++){
                if(!can_place(i, r, c))
                    continue;
                
                // if valid, place it, backtrack and if not valid, remove
                place(i, r, c, board);
                backtrack(nr, nc, board);
                if(is_solved)
                    return;
                remove(i, r, c, board);
            }
        }
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        rows.assign(9, vector<int> (10, 0));
        cols.assign(9, vector<int> (10, 0));
        boxes.assign(9, vector<int> (10, 0));

        // first update rows, cols, boxes with existing numbers
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]!='.')
                    place(board[i][j]-'0', i, j, board);
            }
        }

        backtrack(0, 0, board);
    }
};