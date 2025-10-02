// TC- NK where N is the number of strings and K is the max string length, SC- O(NK)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> map;
        for(int i=0; i<strs.size(); i++)
        {
            vector<int> mem(26,0);
            string s= strs[i];
            for(int j=0; j<s.length();j++)
                mem[int(s[j])-int('a')]++;
            string code="";
            for(int j=0; j<mem.size(); j++)
                code+=mem[j];
            map[code].push_back(strs[i]);
        }
        
        vector<vector<string>> res;
        for(auto key:map)
            res.push_back(key.second);
        return res;
    }
};

// // TC- NKlog(K) where N is the number of strings and K is the max string length, SC- O(NK)
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string,vector<string>> map;
//         for(int i=0; i<strs.size(); i++)
//         {
//             string s= strs[i];
//             sort(s.begin(), s.end());
//             map[s].push_back(strs[i]);
//         }
        
//         vector<vector<string>> res;
//         for(auto key:map)
//             res.push_back(key.second);
//         return res;
//     }
// };