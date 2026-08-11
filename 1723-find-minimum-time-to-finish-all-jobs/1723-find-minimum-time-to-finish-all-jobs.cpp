// TC- O(nlogn+ ((k^n)*log(sum(n)))
// SC- O(k+n)

class Solution {
private:
    bool canFinish(vector<int>& jobs, vector<int>& load, int idx, int max_load){
        if(idx==jobs.size())
            return true;

        int job_load = jobs[idx];
        for(int i=0; i<load.size(); i++){
            if(load[i]+job_load > max_load)
                continue;
            
            // skip if it's a duplicate of any previous seen loads
            bool is_duplicate = false;
            for(int j=0; j<i; j++){
                if(load[j]==load[i]){
                    is_duplicate= true;
                    break;
                }
            }
            if(is_duplicate==true)
                continue;

            load[i] += job_load;

            if(canFinish(jobs, load, idx+1, max_load))
                return true;
            
            load[i] -= job_load;

            if(load[i]==0)
                break;
        }
        return false;
    }

public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int left = *max_element(jobs.begin(), jobs.end());
        int right = accumulate(jobs.begin(), jobs.end(), 0);

        sort(jobs.rbegin(), jobs.rend());

        if(k>=jobs.size())
            return left;
        
        while(left<right){
            int mid = left+(right-left)/2;
            vector<int> load(k, 0);
            if(canFinish(jobs, load, 0, mid))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
};