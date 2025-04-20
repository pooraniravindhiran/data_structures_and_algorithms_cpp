// TC- O(nlogk)
// SC- O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k==nums.size())
            return nums;

        // create freq map
        unordered_map<int, int> freq_map;
        for(int i=0; i<nums.size(); i++){
            if(freq_map.find(nums[i])!=freq_map.end())
                freq_map[nums[i]]++;
            else
                freq_map.insert({nums[i], 1});
        }

        // create a heap of size k and push element one by one. Going for min heap as I don't want to store all n elements
        auto comp = [&freq_map](int n1, int n2){return freq_map[n1]>freq_map[n2];};
        priority_queue<int , vector<int>, decltype(comp)> min_heap(comp);
        for(pair<int,int> p:freq_map){
            min_heap.push(p.first);
            if(min_heap.size()>k)
                min_heap.pop();
        }

        // return output
        vector<int> result(k);
        for(int i=k-1; i>=0; i--){
            result[i] = min_heap.top();
            min_heap.pop();
        }
        return result;
    }
};