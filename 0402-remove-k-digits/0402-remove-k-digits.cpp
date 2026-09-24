// TC- O(n)
// SC- O(n)

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i=0; i<num.size(); i++){
            int curr = num[i];
            while(!st.empty() and st.top()>curr and k>0){
                st.pop();
                k--;
            }
            st.push(curr);
        }
        while(k>0 and !st.empty()){
            st.pop();
            k--;
        }
        
        string res;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }   
        reverse(res.begin(), res.end());
        // cout<<res;

        int i=0;
        while(i<res.size() and res[i]=='0'){
            i++;
        }
        res = res.substr(i);
        return (res.empty())? "0":res;
    }
};