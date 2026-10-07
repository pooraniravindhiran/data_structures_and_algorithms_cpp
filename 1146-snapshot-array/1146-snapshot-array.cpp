// SC- O(s*l)

class SnapshotArray {
public:
    vector<vector<pair<int, int>>> snapshots;
    int snap_id;

    SnapshotArray(int length) {
        snap_id = 0;
        snapshots.resize(length);
        for(int i=0; i<length; i++)
            snapshots[i].push_back({snap_id, 0});
    }
    
    void set(int index, int val) {
        // TC- O(1)
        int curr_snap = snapshots[index].back().first;
        if(curr_snap==snap_id)
            snapshots[index].back().second = val;
        else
            snapshots[index].push_back({snap_id, val});
    }
    
    int snap() {
        // TC- O(1)
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        // TC- O(log s)
        auto & curr_idx = snapshots[index];
        int left = 0, right = curr_idx.size()-1;
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (curr_idx[mid].first <= snap_id) {
                ans = mid;          // valid candidate
                left = mid + 1;     // try to find a later valid one
            }
            else {
                right = mid - 1;    // too large
            }
        }

        return curr_idx[ans].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */