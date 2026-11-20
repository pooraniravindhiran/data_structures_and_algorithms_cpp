// TC- O(w*l)
// SC- O(w*l)

class Solution {
private:
    struct TrieNode{
        TrieNode* children[26] = {};
        bool is_end = false;
    };
    TrieNode* root;

    void insert_string(string word){
        // TC- O(l)
        TrieNode* curr = root;
        for(char ch:word){
            if(curr->children[ch-'a']==NULL)
                curr->children[ch-'a'] = new TrieNode();
            curr = curr->children[ch-'a'];
        }
        curr->is_end = true;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        root = new TrieNode();
        for(int i=0; i<strs.size(); i++)
            insert_string(strs[i]);

        TrieNode* curr = root;
        string ans;
        while(true){
            if(curr->is_end)
                break;
            
            int num_children = 0;
            int next;
            for(int i=0; i<26; i++){
                if(curr->children[i]){
                    num_children++;
                    next = i;
                }
            }

            if(num_children!=1)
                break;
            
            ans += (char) ('a'+next);
            curr = curr->children[next];
        }
        return ans;
    }
};