class Solution {
public:
    int calculate(string s) {
        long long num = 0;
        int sign = 1;
        int ans = 0;
        stack<pair<int, int>> st;

        for(int i=0; i<s.size()+1; i++){
            char ch = (i==s.size()) ? '+':s[i];

            if(ch==' ')
                continue;

            else if(isdigit(ch))
                num = (num*10)+(ch-'0');
            
            else if(ch=='+'){
                ans += (sign*num);
                sign = 1;
                num = 0;
            }

            else if(ch=='-'){
                ans += (sign*num);
                sign = -1;
                num = 0;
            }

            else if(ch=='('){
                st.push({ans, sign});
                num = 0;
                ans = 0;
                sign = 1;
            }

            else{
                auto& top = st.top();
                st.pop();
                ans += (sign*num);
                sign = 1;
                num = 0;
                int prev_ans = top.first;
                int prev_sign = top.second;
                prev_ans += (prev_sign*ans);
                ans = prev_ans;
            }

        }
        return ans;

    }
};