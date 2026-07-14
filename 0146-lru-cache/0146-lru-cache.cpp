class LRUCache {
    // SC- O(k)
public:
    int capacity = 0;
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        // TC- O(1)
        if(mp.find(key)!=mp.end()){
            auto iter = mp[key];
            dll.splice(dll.begin(), dll, iter);
            return dll.front().second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // TC- O(1)

        if(mp.find(key)!=mp.end()){
            auto iter = mp[key];
            dll.splice(dll.begin(), dll, iter);
            dll.front().second = value;
            return;
        }

        if(dll.size()==capacity){
            int remove_key = dll.back().first;
            dll.pop_back();
            mp.erase(remove_key);
        }

        dll.emplace_front(key, value);
        mp[key] = dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */