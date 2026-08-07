// TC- O(b+s)
// SC- O(b+s) where b is num of buses and s is total num of stops across all routes

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target)
            return 0;
        // build stop to bus map
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<routes.size(); i++){
            for(int stop:routes[i])
                mp[stop].push_back(i);
        }

        int ans = 0;
        queue<int> q;
        unordered_set<int> visitedBus, visitedStop;

        q.push(source);
        visitedStop.insert(source);

        while(!q.empty()){
            ans++;

            int qs = q.size();
            while(qs--){

                // pop current
                int currStop = q.front();
                q.pop();

                // iterate through all buses at that stop
                auto buses = mp[currStop];
                for(int b:buses){
                    if(visitedBus.find(b)==visitedBus.end()){
                        visitedBus.insert(b);

                        //visit every stop this bus reaches
                        auto stops = routes[b];
                        for(int stop:stops){
                            if(stop==target)
                                return ans;

                            if(visitedStop.find(stop)==visitedStop.end()){
                                visitedStop.insert(stop);
                                q.push(stop);
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};