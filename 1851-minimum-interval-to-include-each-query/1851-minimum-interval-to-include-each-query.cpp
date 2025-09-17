// TC- O(nlogn + qlogq + nlogn) = O(nlogn +qlogq)
// SC- O(logn + q + n) = O(n+q)

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // bruteforce means checking all interavsl for every query, so TC is n*q. 
        // let's make it optimal by sorting first
        sort(intervals.begin(), intervals.end());
        
        // sort queries too but we need their indices to return ans in right order
        vector<pair<int, int>> sorted_queries;
        for(int i=0; i<queries.size(); i++){
            sorted_queries.push_back({queries[i], i});
        }
        sort(sorted_queries.begin(), sorted_queries.end());

        // use min heap to track candidate intervals
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        vector<int> result(queries.size(), -1);

        int i=0;
        for(auto &[query, idx]:sorted_queries){
            while(i<intervals.size() and query>=intervals[i][0]){
                int int_size = intervals[i][1]-intervals[i][0]+1;
                min_heap.push({int_size, intervals[i][1]});
                i++;
            }
            while(!min_heap.empty() and query>min_heap.top().second){
                min_heap.pop();
            }
            if(!min_heap.empty())
                result[idx] = min_heap.top().first;
        }
        return result;
    }
};