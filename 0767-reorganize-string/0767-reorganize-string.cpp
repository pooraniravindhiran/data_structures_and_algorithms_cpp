// TC- O(n)
// SC- O(1)

class Solution {
private:
    char prev_char = '#';
    priority_queue<pair<int, char>> max_heap;
    vector<int> freq_mp = vector<int> (26, 0);
public:
    string reorganizeString(string s) {
        for(char& ch:s)
            freq_mp[ch-'a']++;
        
        for(int i=0; i<26; i++){
            if(freq_mp[i]){
                max_heap.push({freq_mp[i], i+'a'});
                // cout<<i+'a'<<endl;
            }
        }

        string ans;
        while(!max_heap.empty()){
            auto top = max_heap.top();
            max_heap.pop();
            // cout<< top.second<<endl;
            if(prev_char!=top.second){
                top.first--;
                if(top.first)
                    max_heap.push(top);
                ans += top.second;
                prev_char = top.second;
            }
            else{
                if(max_heap.empty())
                    return "";
                
                auto next = max_heap.top();
                max_heap.pop();
                next.first--;
                if(next.first)
                    max_heap.push(next);
                max_heap.push(top);
                ans += next.second;
                prev_char = next.second;
            }
        }

        if(!max_heap.empty())
            return "";
        
        return ans;
    }
};