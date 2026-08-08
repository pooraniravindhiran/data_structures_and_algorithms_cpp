// TC- O(n^2) since O(g*n^2) but g is bounded and match is O(1) because 6 letters
// SC- O(n)

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
private:
    int match(string& a, string& b){
        int ans = 0;
        for(int i=0; i<a.size(); i++){
            if(a[i]==b[i])
                ans++;
        }
        return ans;
    }
public:
    void findSecretWord(vector<string>& words, Master& master) {
        vector<string> candidates = words;
        while(!candidates.empty()){

            // make a good guess. meaning pick a word, a) find number of matches it will have with every other word. b) group words by number of matches. c) worst case is largest group d) minimize largest group
            int best_idx = 0;
            int best_worstcase = INT_MAX;
            for(int i=0; i<candidates.size(); i++){
                vector<int> count(7, 0); // 0 to all 6 matching
                for(int j=0; j<candidates.size(); j++){
                    int m = match(candidates[i], candidates[j]);
                    count[m]++;
                }

                int worstcase = 0;
                for(int c: count){
                    if(c>worstcase)
                        worstcase = c;
                }

                if(worstcase<best_worstcase){
                    best_idx = i;
                    best_worstcase = worstcase;
                }
            }

            // call master and find match
            string guess = candidates[best_idx];
            int response = master.guess(guess);

            // if 6, then return
            if(response==6)
                return;

            // otherwise, eliminate words from candidate pool that don't go well. meaning which have less match
            vector<string> next;
            for(string& word:candidates){
                if(match(word, guess)==response)
                    next.push_back(word);
            }
            candidates = next;
        }
    }
};