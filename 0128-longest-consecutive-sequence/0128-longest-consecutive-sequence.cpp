// TC- O(n)
// SC- O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest_len = 0;

        for(int num:s){
            // process it as a sequence only if its prev number is not present in the set
            if(!s.count(num-1)){
                int curr_len = 1;
                while(s.count(num+curr_len))
                    curr_len++;
                if(curr_len>longest_len)
                    longest_len=curr_len;
            }
        }
        return longest_len;

    }
};