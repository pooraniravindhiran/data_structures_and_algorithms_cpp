// TC- O(p+n)
// SC- O(n+p)

class Solution {
private:
    vector<vector<int>> adj_mat;
    vector<int> states;
    vector<int> order;
    bool has_cycle(int i){
        if(states[i]==2)
            return false;
        
        if(states[i]==1)
            return true;
        
        states[i] = 1;
        for(int j=0; j<adj_mat[i].size(); j++){
            if(has_cycle(adj_mat[i][j]))
                return true;
        }
        states[i] = 2;
        order.push_back(i);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // create adj matrix
        adj_mat.assign(numCourses, vector<int>());
        for(auto prerequisite:prerequisites)
            adj_mat[prerequisite[1]].push_back(prerequisite[0]);
        
        // go through courses
        order.clear();
        states.assign(numCourses, 0);

        for(int i=0; i<numCourses; i++){
            if(states[i]==0){
                if (has_cycle(i))
                    return {};
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
};