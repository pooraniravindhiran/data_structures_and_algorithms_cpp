// TC- O(m*n)
// SC- O(m*n)

class Solution {
private:
    int rows, cols;
    void dfs(vector<vector<char>>& board, int i, int j){
        // using # to mark all unsurrounded regions instead of keeping track of visited 
        board[i][j] = '#';
        vector<int> directions = {-1, 0, 1, 0, -1};
        for(int d=0; d<directions.size()-1; d++){
            int new_i = i+directions[d];
            int new_j = j+directions[d+1];
            if(new_i>=0 and new_j>=0 and new_i<rows and new_j<cols and board[new_i][new_j]=='O')
                dfs(board, new_i, new_j);
        }
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();

        // find unsurrounded regions
        for(int r=0; r<rows; r++){
            for(int c=0;c<cols; c++){
                if((r==0 or c==0 or r==rows-1 or c==cols-1) and board[r][c]=='O'){
                    dfs(board, r, c);
                }
            }
        }

        // Change # into O and O into X
        for(int r=0; r<rows; r++){
            for(int c=0;c<cols; c++){
                if(board[r][c]=='#')
                    board[r][c]= 'O';
                else if(board[r][c]=='O')
                    board[r][c]= 'X';
            }
        }
        return;
    }
};