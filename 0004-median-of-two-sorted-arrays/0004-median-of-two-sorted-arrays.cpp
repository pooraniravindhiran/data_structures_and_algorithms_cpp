// TC- O(log(min(m, n)))
// SC- O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // merging is O(m+n), instead find a cut in nums1 at mid_i that will split it into elements that go into left and right of merged array. Similarly for nums2 at mid_j = halflen-mid_i. You can do binary search to find cut on smallest array. So TC is O(log(min(m, n)))

        if(nums1.size()>nums2.size())
            swap(nums1, nums2);

        int m = nums1.size(), n=nums2.size();
        int halflen = (m+n+1)/2;

        int left = 0, right = m; // cut can be even at m
        while(left<=right){
            // partition is valid if Aleft<=Bright and Bleft<=Aright
            // if partition is invalid:
                // move cut in nums1 to right if Bleft>Aright
                // move cut in nums1 to left if Aleft>Bright
            
            int mid_i = left+(right-left)/2;
            int mid_j = halflen-mid_i;

            if(mid_i<m and mid_j>0 and nums2[mid_j-1]>nums1[mid_i])
                left = mid_i+1;
            else if(mid_i>0 and mid_j<n and nums1[mid_i-1]>nums2[mid_j])
                right = mid_i-1;
            else{
                // cut is found, find median
                int max_left;
                if(mid_i==0)
                    max_left = nums2[mid_j-1];
                else if(mid_j==0)
                    max_left = nums1[mid_i-1];
                else
                    max_left = max(nums1[mid_i-1], nums2[mid_j-1]);
                
                if((m+n)%2!=0)
                    return max_left;
                
                int min_right;
                if(mid_i==m)
                    min_right = nums2[mid_j];
                else if(mid_j==n)
                    min_right = nums1[mid_i];
                else
                    min_right = min(nums1[mid_i], nums2[mid_j]);

                return (min_right+max_left)/2.0;
            }

        }
        return 0.0;

    }
};