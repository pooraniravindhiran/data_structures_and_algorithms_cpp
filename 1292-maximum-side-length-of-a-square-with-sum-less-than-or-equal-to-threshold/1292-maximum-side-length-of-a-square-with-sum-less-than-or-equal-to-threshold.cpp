// TC- O(mnlog(min(m, n))
// SC- O(mn)

class Solution {
private:
    vector<vector<int>> ps;
    bool is_possible(int side, int t){
        int m = ps.size()-1;
        int n = ps[0].size()-1;

        for(int i=0; i<m-side+1; i++){
            for(int j=0; j<n-side+1; j++){
                // i to i+2, j to j+2
                int sum_sq = ps[i+side][j+side]-ps[i][j+side]-ps[i+side][j]+ps[i][j];
                if(sum_sq<=t)
                    return true;
            }
        }
        return false;
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        ps.assign(m+1, vector<int>(n+1, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ps[i+1][j+1] = ps[i][j+1] + ps[i+1][j] -ps[i][j]+mat[i][j];
            }
        }

        int left = 1;
        int right = min(m, n);
        int ans = 0;

        while(left<=right){
            int mid = left+(right-left)/2;
            if(is_possible(mid, threshold)){
                ans = mid;
                left = mid+1;
            }
            else
                right = mid-1;
        }
        return ans;
    }
};