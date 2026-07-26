// TC- O(n)
// SC- O(n)

class Solution {
public:
    int calculate(string s) {
        int res = 0;
        stack<pair<int, int>> st; // prev result, sign 

        int sign = 1;
        long long curr_num = 0;

        for(int i=0; i<s.size(); i++){
            char ch = s[i];

            if(ch==' ')
                continue;
            else if(isdigit(ch))
                curr_num = (curr_num*10)+(ch-'0');
            else if(ch=='+'){
                res += sign* curr_num;
                sign = 1;
                curr_num = 0;
            }
            else if(ch=='-'){
                res += sign * curr_num;
                sign = -1;
                curr_num = 0;
            }
            else if(ch=='('){
                st.push({res, sign});
                sign = 1;
                curr_num = 0;
                res = 0;
            }
            else if (ch==')'){
                res += sign*curr_num;

                auto [prev_res, prev_sign] = st.top();
                st.pop();

                res = prev_res+ prev_sign*res;
                curr_num = 0;
                sign = 1;
            }
        }
        res += sign*curr_num;
        return res;
    }
};