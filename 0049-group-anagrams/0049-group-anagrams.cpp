// TC- O(N*L) where N is num_words and L is len of a word
// SC- O(N*L)

class Solution {
private:
    unordered_map<string, vector<string>> mp;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for(string word:strs){
            // create freq vector
            vector<int> freq(26, 0);
            for(char ch:word)
                freq[ch-'a']++;
            
            // convert freq vector to string to store as key
            string code="";
            for(int i=0; i<26; i++)
                code += to_string(freq[i]) + '#';
            
            // add to unordered_map
            mp[code].push_back(word);
        }

        vector<vector<string>> result;
        for(auto& [key, words]:mp){
            result.push_back(words);
        }
        return result;
    }
};