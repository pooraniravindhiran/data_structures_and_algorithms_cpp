// TC- O(t+tlogt+t+t) = O(tlogt)
// SC- O(t)

class Solution {
private:
    
    unordered_map<string, vector<string>> adjmap;
    vector<string> itinerary;
    void dfs(string airport){
        while(!adjmap[airport].empty()){
            string smallest = adjmap[airport].back();
            adjmap[airport].pop_back();
            dfs(smallest);
        }
        itinerary.push_back(airport);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // create adj matrix
        for(auto& ticket:tickets)
            adjmap[ticket[0]].push_back(ticket[1]);

        // must use every edge once, so we pop ticket once used. popping from vector is O(1) if at end- so sort tickets in reverse order
        for(auto& [airport, destinations]:adjmap)
            sort(destinations.rbegin(), destinations.rend());

        dfs("JFK");
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};