class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // pass1
        long result=0;
        for(int i=0; i<nums.size(); i++)
           result^= nums[i];
        
        // cout<<(result & (-result))<<endl;
        // find last set bit in result
        result&=~(result-1);
        
        //pass2
        vector<int> ans{0,0};
        for(int i=0; i<nums.size();i++){
            // cout<<ans[0]<<endl;
            // check if that bit is set in nums[i]
            if((nums[i]&result)==0){
                // cout<<"unset: "<<nums[i]<<endl;
                ans[0]^= nums[i];
            }
            else{
                // cout<<"set: "<<nums[i]<<endl;
                ans[1]^=nums[i];
            }
        }
        return ans;
    }
};