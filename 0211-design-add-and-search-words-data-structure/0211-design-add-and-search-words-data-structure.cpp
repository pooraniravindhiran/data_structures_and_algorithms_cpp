// SC- O(t+l) where t is total num of letters you come across and l is num of letters in input word

class WordDictionary {
private:
    struct TrieNode{
        TrieNode* children[26] = {};
        bool isEnd = false;
    };
    TrieNode* root;

    bool dfs(TrieNode* node, string& word, int i){
        if(i==word.size())
            return node->isEnd;
        
        char ch = word[i];
        if(ch!='.'){
            int idx = ch-'a';
            if(node->children[idx]==NULL)
                return false;
            return dfs(node->children[idx], word, i+1);
        }
        for(int j=0; j<26; j++){
            if(node->children[j]!=NULL and dfs(node->children[j], word, i+1))
                return true;
        }
        return false;
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        // TC- O(l)
        TrieNode* curr = root;
        for(char ch:word){
            int idx = ch-'a';
            if(curr->children[idx]==NULL)
                curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        // TC- O(26^l)
        return dfs(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */