// TC- O(m*n)
// SC- O(m*n)

class Solution {
    int m,n;
    int fresh_oranges = 0;
    vector<int> directions = {-1,0,1,0,-1};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        queue<pair<int,int>> q;

        // count number of fresh oranges to check there is none remaining at the end and add rotting orange to queue
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1)
                    fresh_oranges++;
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        
        int minutes=0;
        while(!q.empty() and fresh_oranges>0){
            int qsize = q.size();
            // to check if there is atleast one fresh orange converted to rotten. what if all are empty cells surrounding a rotten cell
            bool rotted=false;
            for(int i=0; i<qsize; i++){
                pair<int,int> curr=q.front();
                q.pop();
                for(int d=0; d<directions.size()-1; d++){
                    int new_r = curr.first+directions[d];
                    int new_c = curr.second+directions[d+1];
                    if(new_r>=0 and new_r<m and new_c>=0 and new_c<n and grid[new_r][new_c]==1){
                        // make cell rotten
                        grid[new_r][new_c] = 2;
                        fresh_oranges--;
                        q.push({new_r, new_c});
                        rotted=true;
                    }
                }
            }
            if(rotted)
                minutes++;
        }

        return fresh_oranges>0? -1:minutes;
    }
};