class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // create adj list
        vector<vector<pair<int,int>>> adjlist(n);
        for(auto flight: flights) {
            adjlist[flight[0]].push_back({flight[1], flight[2]});
        }

        // cost table to store the minimum cost to reach city with specific remaining stops
        vector<vector<int>> cost(n, vector<int>(k + 2, INT_MAX)); // k+2 because k stops means k+1 flights and 0 included
        
        // Create priority queue to store route with minimum cost
        // It stores cost, current_city, number of flights remaining 
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> min_heap;
        min_heap.push({0, src, k + 1});
        
        // Initialize cost table for the source city with k + 1 stops(1d arr becomes 2d arr)
        cost[src][k + 1] = 0;

        while(!min_heap.empty()) {
            auto [cur_cost, city, rem_flights] = min_heap.top();
            min_heap.pop();

            // If we reached the destination, return the cost
            if (city == dst)
                return cur_cost;

            // If there are no remaining flights, continue
            if (rem_flights > 0) {
                for (auto [neighbor, price] : adjlist[city]) {
                    int new_cost = cur_cost + price;

                    // Only push the state if it offers a cheaper way to reach the neighbor with rem_flights-1 stops
                    if (new_cost < cost[neighbor][rem_flights - 1]) {
                        cost[neighbor][rem_flights - 1] = new_cost;
                        min_heap.push({new_cost, neighbor, rem_flights - 1});
                    }
                }
            }
        }

        // If we exhaust the priority queue without finding a path to destination
        return -1;
    }
};
