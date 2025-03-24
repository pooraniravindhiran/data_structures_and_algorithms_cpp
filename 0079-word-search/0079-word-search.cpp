// TC- O(m*n*(3^k)) where m,n are board size, k is word length
// SC- O(k) due to recursion stack
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();

        vector<int> dir= {-1, 0, 1, 0, -1};
        function<bool(int, int, int)> dfs= [&](int a, int b, int w){
            if (word.size() == w)
                return true;

            char temp = board[a][b];
            board[a][b] = '#';

            int row, col;
            for(int k=0; k<dir.size()-1; k++){
                row= a+dir[k];
                col= b+dir[k+1];
                if(row>=0 and col>=0 and row<r and col<c and word[w]==board[row][col]){
                    if (dfs(row, col, w+1))
                        return true;
                }
            }
            board[a][b] = temp;
            return false;
        };

        // Iterate through board to find starting letter matches and call dfs
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if (word[0]==board[i][j]){
                    if (dfs(i, j, 1))
                        return true;
                }
            }
        }
        return false;
    }
};