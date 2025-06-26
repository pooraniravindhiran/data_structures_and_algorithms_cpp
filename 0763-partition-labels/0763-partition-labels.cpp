// TC- O(n)
// SC - O(k)  where k is num_distinct_letters in s

class Solution {
public:
    vector<int> partitionLabels(string s) {
        // First pass: Store the last index of each character in 's'
        vector<int> lastocc(26);
        for(int i=0; i<s.length(); i++){
            lastocc[s[i]-'a'] = i;
        }

        // Second pass
        vector<int> partition_sizes;
        int ps = 0; // partition_start
        int pe = 0; // partition_end
        for(int i=0; i<s.length(); i++){
            pe = max(pe, lastocc[s[i]-'a']);
            if(i==pe){
                partition_sizes.push_back(pe-ps+1);
                ps = i+1;
            }
        }
        return partition_sizes;
    }
};