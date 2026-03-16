class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        // we pick BFS because we need to find the distance to the "nearest" gate
        // we can do BFS from gate or empty room. If done from empty room, then we need to do BFS from every room- so O(mn*mn). If done from every gate, then we do O(G*mn). But if we push all gates into queue first and then do BFS, we visit every cell only once- so TC is O(mn). So we pick the last option- which is multi source BFS

        int rows = rooms.size();
        int cols = rooms[0].size();
        queue<pair<int,int>> q;
        vector<int> directions = {1, 0, -1, 0, 1};

        // push all gates into the queue
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(rooms[i][j]==0)
                    q.push({i,j});
            }
        }

        int level =0;
        while(!q.empty()){
            int q_size = q.size();
            for(int i=0; i<q_size; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if(rooms[r][c] == INT_MAX)
                    rooms[r][c] = level;
                for(int d=0; d<directions.size()-1; d++){
                    int next_r = r+directions[d];
                    int next_c = c+directions[d+1];
                    if(next_r>=0 and next_r<rows and next_c>=0 and next_c<cols and rooms[next_r][next_c]==INT_MAX)
                        q.push({next_r, next_c});
                }
                
            }
            level++;
        }
    }
};