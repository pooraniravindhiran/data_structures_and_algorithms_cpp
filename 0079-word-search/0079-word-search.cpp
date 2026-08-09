// TC- O(mn* 4^l)
// SC- O(l)

class Solution {
private:
    int m, n;
    vector<int> dirs = {-1, 0, 1, 0, -1};
    bool dfs(int r, int c, vector<vector<char>>& board, string& word, int i){
        if(i==word.size())
            return true;

        // Mark as visited
        char original = board[r][c];
        board[r][c] = '#';

        for(int d=0; d<dirs.size()-1; d++){
            int next_r = r+dirs[d];
            int next_c = c+dirs[d+1];
            if(next_r>=0 and next_r<board.size() and next_c>=0 and next_c<board[0].size() and board[next_r][next_c]!='#' and board[next_r][next_c]==word[i]){
                if(dfs(next_r, next_c, board, word, i+1))
                    return true;
            }
        }
        board[r][c] = original;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(); n=board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==word[0]){
                    if (dfs(i, j, board, word, 1))
                        return true;
                }
            }
        }
        return false;
    }
};