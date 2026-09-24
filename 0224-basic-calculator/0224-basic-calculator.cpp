// TC- O(n)
// SC- O(n)

class Solution {
private:
    stack<pair<int, int>> st;

public:
    int calculate(string s) {
        int ans = 0;
        long long num = 0;
        int sign = 1;

        for(char ch:s){
            if(ch==' ')
                continue;
            
            else if(isdigit(ch))
                num = (num*10)+ (ch-'0');
            
            else if(ch=='+'){
                ans += (sign*num);
                num = 0;
                sign = 1;
            }

            else if(ch=='-'){
                ans += (sign*num);
                num = 0;
                sign = -1;
            }

            else if(ch=='('){
                st.push({ans, sign});
                ans = 0;
                sign = 1;
            }

            else if(ch==')'){
                if(!st.empty()){
                    auto [prev_ans, prev_sign] = st.top();
                    st.pop();
                    ans += (sign*num);
                    ans = prev_ans + (prev_sign*ans);
                    sign = 1;
                    num = 0;
                }
            }
        }
        if(s[s.size()-1]!=')')
            ans += (sign*num);
        return ans;
    }
};