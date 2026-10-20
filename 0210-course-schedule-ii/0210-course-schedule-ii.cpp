class Solution {
private:
    vector<int> state;
    bool has_cycle(int i, vector<vector<int>>& adj_mat, vector<int>& order){
        if(state[i]==1)
            return true;
        
        state[i] = 1;

        for(int& edge:adj_mat[i]){
            if(state[edge]!=2){
                if (has_cycle(edge, adj_mat, order))
                    return true;
            }
        }

        state[i] = 2;
        order.push_back(i);
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;

        // create adj mat
        vector<vector<int>> adj_mat(numCourses, vector<int>());
        for(auto prereq:prerequisites)
            adj_mat[prereq[1]].push_back(prereq[0]);

        state.assign(numCourses, 0);

        for(int i=0; i<numCourses; i++){
            if(state[i]==0){
                if (has_cycle(i, adj_mat, order))
                    return {};
            }
        }

        reverse(order.begin(), order.end());
        return order;
    }
};