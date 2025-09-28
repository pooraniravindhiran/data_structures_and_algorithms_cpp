
// TC- O(V+E)
// SC- O(V+E)
class Solution {
private:
    vector<int> order;
    bool hascycle(vector<vector<int>>& adjlist, vector<int>& state, int i){
        if(state[i]==1)
            return true;
        state[i]=1;
        for(auto neigh:adjlist[i]){
            if(state[neigh]!=2){
                if(hascycle(adjlist, state, neigh))
                    return true;
            }
        }
        state[i]=2;
        order.push_back(i);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //if there is a cycle, you can't finish. else you can
        // create adj list to represent problem as graph
        vector<vector<int>> adjlist(numCourses);
        for(int p=0; p<prerequisites.size(); p++)
            adjlist[prerequisites[p][1]].push_back(prerequisites[p][0]);

        // for it to be a cycle - it should revisit an ancestor in current recursion stack
        // create state array to track visited- 0 is not visited, 1 is visiting, 2 is visited
        vector<int> state(numCourses, 0); 

        // start dfs for every course that is not visited
        for(int i=0; i<numCourses; i++){
            if(state[i]!=2){
                if(hascycle(adjlist, state, i))
                    return {};
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
};
