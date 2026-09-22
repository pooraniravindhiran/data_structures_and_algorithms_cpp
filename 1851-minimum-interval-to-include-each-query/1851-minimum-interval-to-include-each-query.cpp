// TC- O(ilogi+qlogq)
// SC- O(i+q)

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<vector<int>> sorted_intervals;
        for(int i=0; i<intervals.size(); i++)
            sorted_intervals.push_back({intervals[i][0], intervals[i][1], i});
        sort(sorted_intervals.begin(), sorted_intervals.end());

        vector<vector<int>> sorted_queries;
        for(int i=0; i<queries.size(); i++)
            sorted_queries.push_back({queries[i], i});
        sort(sorted_queries.begin(), sorted_queries.end());
        int j=0;
    
        vector<int> ans(queries.size(), -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

        for(int i=0; i<sorted_queries.size(); i++){
            int query = sorted_queries[i][0];

            while(j<sorted_intervals.size() and sorted_intervals[j][0]<=query){
                min_heap.push({sorted_intervals[j][1]-sorted_intervals[j][0]+1, j});
                j++;
            }

            while(!min_heap.empty() and sorted_intervals[min_heap.top().second][1]<query){
                min_heap.pop();
            }

            if(!min_heap.empty())
                ans[sorted_queries[i][1]] = min_heap.top().first;
        }
        return ans;
    }
};