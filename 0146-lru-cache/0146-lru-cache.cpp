// SC- O(k)

class LRUCache {
public:
    int capacity = 0;
    list<pair<int,int>> dll;
    unordered_map<int, list<pair<int,int>>::iterator> mp;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        // TC- O(1)
        if(mp.find(key)==mp.end())
            return -1;
        
        // update cache and return value
        auto it = mp[key];
        dll.splice(dll.begin(), dll, it);
        return dll.front().second;
    }
    
    void put(int key, int value) {
        // TC- O(1)
        // if key there
        if(mp.find(key)!=mp.end()){
            // update map
            auto it = mp[key];
            it->second = value;

            // update cache
            dll.splice(dll.begin(), dll, it);
            return;
        }

        // if cache full
        if(dll.size()==capacity){
            auto lru = dll.back();
            mp.erase(lru.first);
            dll.pop_back();
        }
        // if there
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */