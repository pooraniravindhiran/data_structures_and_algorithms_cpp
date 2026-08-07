// TC- O(nlogn+nL) where l is avg folder path length
// SC- O(n)

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> res;
        res.push_back(folder[0]);

        for(int i=1; i<folder.size(); i++){
            string lastfolder = res.back();

            // if folder doesn't start with lastfolder or it does but does'nt end with /, then add
            if(folder[i].compare(0, lastfolder.size(), lastfolder)!=0 or folder[i][lastfolder.size()]!='/')
                res.push_back(folder[i]);
        }
        return res;
    }
};