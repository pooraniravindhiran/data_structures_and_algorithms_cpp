// SC- O(l*s)

class SnapshotArray {
public:
    int snapId;
    vector<vector<pair<int, int>>> records;

    SnapshotArray(int length) {
        snapId = 0;
        records.resize(length);
        for(int i=0; i<length; i++){
            records[i].push_back({0, 0});
        }
    }
    
    void set(int index, int val) {
        // TC- O(1)
        if(records[index].back().first==snapId)
            records[index].back().second = val;
        else
            records[index].emplace_back(snapId, val);
    }
    
    int snap() {
        // TC- O(1)
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        // TC- O(logl)
        // find rightmost occ
        auto & l = records[index];
        int left =0;
        int right = l.size()-1;
        int ans = 0;
        while(left<=right){
            int mid = left + (right-left)/2;
            if (l[mid].first>snap_id)
                right = mid-1;
            else{
                ans = mid;
                left = mid+1;
            }
        }
        return l[ans].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */