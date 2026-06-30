class TimeMap {
public:

    unordered_map<string, vector<pair<int, string>>> mp; 
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (mp[key].size()==0)
            return "";
        
        string ans = "";
        int left =0;
        int right = mp[key].size()-1;
        while(left<=right){
            int mid = left +(right-left)/2;
            if (mp[key][mid].first>timestamp)
                right = mid-1;
            else{
                ans = mp[key][mid].second;
                left = mid+1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */