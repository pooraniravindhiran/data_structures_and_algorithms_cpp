// TC- O(n)
// SC- O(n)

class Solution {
public:
    int calculate(string s) {
        int res = 0;

        int sign = 1;
        long long num = 0;
        stack<pair<int, int>> st; // Stack needed because nested brackets, pair needed because I can't apply the sign until I get the next number, so need to store sign and prev res in stack.

        for(char ch:s){
            if(ch==' ')
                continue;
            else if(isdigit(ch))
                num = (num*10)+ch-'0';
            else if(ch=='+'){
                res += (sign*num);
                num = 0;
                sign = 1;
            }
            else if(ch=='-'){
                res += (sign*num);
                num = 0;
                sign = -1;
            }
            else if(ch=='('){
                st.push({res, sign});
                num = 0;
                sign = 1;
                res = 0;
            }
            else{
                res += (sign*num);
                auto [prev_num, prev_sign] = st.top();
                st.pop();
                res = prev_num +(prev_sign*res);
                sign = 1;
                num = 0;
            }
        }
        res += (sign*num);
        return res;
    }
};