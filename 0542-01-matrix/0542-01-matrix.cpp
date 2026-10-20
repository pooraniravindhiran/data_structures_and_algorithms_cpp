// TC- O(mn)
// SC- O(mn)

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int directions[5]={0,1,0,-1,0};
        vector<vector<int>> dist(mat.size(), vector<int> (mat[0].size(), -1));
        //pushing all zeroes to queue
        for(int i=0; i<mat.size();i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.emplace(i,j);
                }
            }
        }
        
        
        // do multisource bfs
        while(!q.empty()){
            int size= q.size();
            for(int i=0; i<size; i++){
                int r= q.front().first, c=q.front().second;
                for(int d=0; d<4; d++){
                    int next_r= r+directions[d];
                    int next_c= c+directions[d+1];
                    if(next_r>=0 and next_r<mat.size() and next_c>=0 and next_c<mat[0].size() and dist[next_r][next_c]==-1){
                        q.emplace(next_r,next_c);
                        dist[next_r][next_c]= dist[r][c]+1;
                    }
                }
                q.pop();
            }
        }
    return dist;
    }
};