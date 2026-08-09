class Trie {
private:
// SC- O(t) where t is total num of chars inserted
     struct TrieNode {
        TrieNode* children[26] = {};
        bool isEnd = false;
    };

    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        // TC- O(l)
        TrieNode* curr = root;
        for(char ch:word){
            if(curr->children[ch-'a']==NULL)
                curr->children[ch-'a'] = new TrieNode();
            curr = curr->children[ch-'a'];
        }
        curr->isEnd= true;
    }
    
    bool search(string word) {
        // TC- O(l)
        TrieNode* curr = root;
        for(char ch:word){
            if(curr->children[ch-'a']==NULL)
                return false;
            curr = curr->children[ch-'a'];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        // TC- O(l)
        TrieNode* curr = root;
        for(char ch:prefix){
            if(curr->children[ch-'a']==NULL)
                return false;
            curr = curr->children[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */