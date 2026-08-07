// TC- O(nm)
// SC- O(1)

// better solution using binary search exists

class Solution {
public:
    int shortestWay(string source, string target) {
        // if any letter in target is not there in src, then -1
        // otherwise, inc letter in target, if there, keep inc till you find it src. if src ptr comes to end, then inc ans.

        unordered_set<char> in_src;
        for(char ch:source)
            in_src.insert(ch);
        
        for(char ch:target){
            if(in_src.find(ch)==in_src.end())
                return -1;
        }

        int ans = 0, i=0;
        while(i<target.size()){

            for(char j:source){
                if(j==target[i])
                    i++;
            }
            ans++;
        }
        return ans;
    }
};