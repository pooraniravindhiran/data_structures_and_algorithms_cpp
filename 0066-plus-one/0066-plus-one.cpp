class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry= 1;
        for(int i=digits.size()-1; i>=0; i--){
            int sum= digits[i]+carry;
            carry= sum/10;
            if(sum<10)
                digits[i]=sum;
            else
                digits[i]=0;
        }
        if(carry)
            digits.insert(digits.begin(),1);
        return digits;
    }
};