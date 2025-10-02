class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> mem(26, 0);
        for(auto ch:s){
            mem[ch-'a']++;
        }

        for(auto ch:t){
            mem[ch-'a']--;
        }

        for(auto i:mem){
            if(i!=0)
                return false;
        }
        return true;
    }
};