// TC- O(n)
// SC- O(1)

class Solution {
public:
    int compress(vector<char>& chars) {
        int rewrite_idx = 0;
        int curr_idx = 0;
        while(curr_idx<chars.size()){
            int curr_len = 1;
            while(curr_idx+1<chars.size() and chars[curr_idx]==chars[curr_idx+1]){
                curr_len++;
                curr_idx++;
            }

            chars[rewrite_idx++] = chars[curr_idx];
            if(curr_len>1){
                string curr_len_str = to_string(curr_len);
                for(auto ch:curr_len_str)
                    chars[rewrite_idx++] = ch;
            }
            curr_idx++;
        }
        return rewrite_idx;
    }
};