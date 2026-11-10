// TC- O(n+e)
// SC- O(n+e)

class Solution {
private:
    vector<vector<int>> adj_mat;
    int min_sems = 0;
    vector<int> degree;
    int processed = 0;
    
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        adj_mat.resize(n+1, vector<int> ());
        degree.resize(n+1, 0);
        
        // create adj mat and find num_prereq for every course
        for(auto& relation: relations){
            int prereq = relation[0];
            int next = relation[1];
            degree[next]++;
            adj_mat[prereq].push_back(next);
        }
        
        queue<int> q;
        // add all courses with 0 prereq to queue and start BFS
        for(int i=1; i<=n; i++){
            if(degree[i]==0)
                q.push(i);
        }
        
        while(!q.empty()){
            min_sems++;
            int q_size = q.size();
            for(int i=0; i<q_size; i++){
                // pop current in the q
                int curr = q.front();
                q.pop();
                processed++;
                
                // for its neighbors, decrease degree( ie num of prerequisites)
                for(auto& neigh:adj_mat[curr]){
                    degree[neigh]--;
                    
                    if(degree[neigh]==0)
                        q.push(neigh);
                }   
            }
        }
        
        // detect cycle
        if(processed!=n)
            return -1;
        
        return min_sems;
        
        
    }
};