// TC- O(m*n)
// SC- O(m*n)

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        // go from gates and add all gates to queue
        queue<pair<int, int>> q;
        int r = rooms.size();
        int c = rooms[0].size();
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(rooms[i][j]==0)
                    q.emplace(i,j);
            }
        }

        // do multisource bfs
        vector<int> dir = {-1, 0, 1, 0, -1};
        while(!q.empty()){
            int qsize = q.size();
            for(int i=0; i<q.size(); i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(int d=0; d<dir.size()-1; d++){
                    int next_row = row + dir[d];
                    int next_col = col+ dir[d+1];
                    if(next_row>=0 and next_row<r and next_col>=0 and next_col<c and rooms[next_row][next_col]>rooms[row][col]+1){
                        rooms[next_row][next_col] = rooms[row][col]+1;
                        q.emplace(next_row, next_col);
                    }
                }
            }
        }
    }
};