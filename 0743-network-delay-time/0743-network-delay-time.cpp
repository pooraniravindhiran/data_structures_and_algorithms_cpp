class Solution {
private:
    vector<int> dist; // shortest time from source k to node
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // graph[u] = {v, time}
        vector<vector<pair<int, int>>> graph(n + 1);

        for (auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            graph[u].push_back({v, w});
        }

        dist.assign(n+1, INT_MAX);
        dist[k] = 0;
        min_heap.push({0, k});

        while(!min_heap.empty()){
            auto [curr_dist, u] = min_heap.top();
            min_heap.pop();

            if(curr_dist > dist[u])
                continue;

            for(int i=0; i<graph[u].size(); i++){
                int distance = graph[u][i].second;
                int v = graph[u][i].first;

                int distance_to_k = curr_dist+distance;
                if(dist[v]>distance_to_k){
                    dist[v] = distance_to_k;
                    min_heap.push({dist[v], v});
                }
            }
        }

        // Signal must reach EVERY node
        int answer = 0;

        for (int i = 1; i <= n; i++) {

            if (dist[i] == INT_MAX)
                return -1;

            answer = max(answer, dist[i]);
        }

        return answer;
    }

};