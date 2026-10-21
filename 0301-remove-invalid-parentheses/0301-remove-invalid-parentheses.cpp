class Solution {
private:
    bool is_valid(string s){
        // TC- O(l)
        // SC- O(l)
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(')
                st.push('(');
            else if (s[i]==')'){
                if(st.empty())
                    return false;
                st.pop();
            }
        }
        if(!st.empty())
            return false;
        return true;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        // SC - O(2^l)
        queue<string> q;
        unordered_set<string> visited;

        q.push(s);
        visited.insert(s);
        bool found = false;
        vector<string> ans;

        while(!q.empty()){
            int q_size = q.size();
            for(int i=0; i<q_size; i++){
                // pop first
                string curr = q.front();
                q.pop();

                if(is_valid(curr)){
                    ans.push_back(curr);
                    found = true;
                    continue;
                }

                // modify one edge
                for(int j=0; j<curr.size(); j++){
                    if(curr[j]!='(' and curr[j]!=')')
                        continue;
                    
                    // remove j and get remaining string
                    string modified = curr.substr(0, j) + curr.substr(j + 1);
                    if(visited.find(modified)!=visited.end())
                        continue;

                    q.push(modified);
                    visited.insert(modified);
                }

            }
            if(found)
                return ans;
        }

        return ans;
    }
};