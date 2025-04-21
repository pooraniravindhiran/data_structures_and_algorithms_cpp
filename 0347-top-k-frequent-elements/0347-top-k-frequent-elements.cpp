// SC- O(n)
// TC- O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;

        // create freq map
        unordered_map<int, int> freqmap;
        for(int num:nums)
            freqmap[num]++;

        // create a priority queue based on frequencies
        auto cmp = [&freqmap](int a, int b){return freqmap[a]>freqmap[b];};
        priority_queue<int, vector<int>, decltype(cmp)> min_heap(cmp);
        for(auto pair: freqmap){
            min_heap.push(pair.first);
            if(min_heap.size()>k)
                min_heap.pop();
        }

        while(!min_heap.empty()){
            res.push_back(min_heap.top());
            min_heap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};