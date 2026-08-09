// TC- O(wl+mn(4^l))
// SC- O(wl)

class Solution {
private:
    int m, n;
    vector<int> dirs = {-1, 0, 1, 0, -1};
    vector<string> res;
    struct TrieNode{
        TrieNode* children[26] = {};
        string word = ""; // marks end
    };
    TrieNode* root;

    void insert(string& word){
        TrieNode* curr = root;
        for(char ch:word){
            int idx = ch-'a';
            if(curr->children[idx]==NULL)
                curr->children[idx]= new TrieNode();
            curr = curr->children[idx];
        }
        curr->word = word;
    }

    void dfs(int r, int c, TrieNode* node, vector<vector<char>>& board){
        char ch = board[r][c];
        board[r][c] = '#';
        int idx = ch-'a';
        if(node->children[idx]!=NULL){
            // if is end, add to res
            TrieNode* next = node->children[idx];
            if(next->word!=""){
                res.push_back(next->word);
                // avoid finding same word again
                next->word = "";
            }

            // check 4 neighbors- within grid and not visited and node->children
            for(int d=0; d<dirs.size()-1; d++){
                int next_r = r+dirs[d];
                int next_c = c+dirs[d+1];
                if(next_r>=0 and next_r<m and next_c>=0 and next_c<n and board[next_r][next_c]!='#'){
                    dfs(next_r, next_c, next, board);
                }
            }
        }
        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        // insert it all into a trie
        root = new TrieNode();
        for(auto word:words){
            insert(word);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dfs(i, j, root, board);
            }
        }
        return res;
    }
};