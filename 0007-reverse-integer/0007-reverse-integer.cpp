class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x){
            int rem = x%10;
            x = x/10;
            if(rev>INT_MAX/10 or (rev==INT_MAX/10 and rem>7))
                return 0;
            if(rev<INT_MIN/10 or (rev==INT_MIN/10 and rem<=-8))
                return 0;    
            rev = rev*10+rem;
        }
        return rev;
    }
};