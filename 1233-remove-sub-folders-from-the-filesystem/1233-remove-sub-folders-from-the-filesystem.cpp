// TC- O (nllogn)
// SC- O(logn)

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        // for(int i=0; i<folder.size(); i++){
        //     cout<<folder[i]<<endl;
        // }
        // return vector<string> (5, "0");

        vector<string> result;
        result.push_back(folder[0]);
        for(int i=1; i<folder.size(); i++){
            string lastfolder = result.back();
            if(folder[i].compare(0, lastfolder.size(), lastfolder)!=0 || folder[i][lastfolder.size()]!='/')
                result.push_back(folder[i]);
        }

        return result;
    }
};