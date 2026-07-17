// TC- O(nlog26)
// SC- O(26)

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq_map;
        for(auto& ch:s)
            freq_map[ch]++;

        priority_queue<pair<int, char>> max_heap;
        for(auto& [ch, freq]:freq_map)
            max_heap.push({freq, ch});
        
        pair<int, char> prev = {0, '#'};
        string ans;

        while(!max_heap.empty()){
            auto curr = max_heap.top();
            max_heap.pop();

            ans += curr.second;

            if (prev.first>0)
                max_heap.push(prev);

            --curr.first;
            prev = curr;
        }

        return ans.size()==s.size() ? ans:"";
    }
};