class Solution {
private:
    int rows, cols;
    vector<int> directions={-1,0,1,0,-1};
    bool dfs(pair<int,int> cell, vector<vector<char>>& board, string word){
        if(word.size()==0)
            return true;
        
        // mark visited by some indicator- no need of extra space
        int i=cell.first;
        int j=cell.second;
        char temp = board[i][j];
        board[i][j] = '#';

        for(int d=0; d<directions.size()-1; d++){
            int new_i = i+directions[d];
            int new_j = j+directions[d+1];
            if(new_i<rows and new_j<cols and new_i>=0 and new_j>=0 and word[0]==board[new_i][new_j]){
                if(dfs({new_i, new_j}, board, word.substr(1)))
                    return true;
            }
        }

        // after you've checked all paths from curr cell, replace it with original char
        board[i][j]=temp;
        return false;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows=board.size();
        cols=board[0].size();
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(board[i][j]==word[0]){
                    if(dfs({i,j}, board, word.substr(1)))
                        return true;
                }
            }
        }
        return false;
    }
};