// SC - O(capacity)

class LRUCache {
private:
    int capacity;

    // need track of MRU to LRU, and to update it in O(1). so double ended linked list. it should contain key and value 
    list<pair<int,int>> dq;

        // need to be able to lookup in list at O(1). so use unordered map to store key and list iterator
    unordered_map<int, list<pair<int,int>>::iterator> map;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        // TC- O(1)
        if(map.count(key)==0)
            return -1;
        auto it = map[key];
        dq.splice(dq.begin(), dq, it);
        return it->second;
    }
    
    void put(int key, int value) {
        // TC- O(1)
        if(map.count(key)==0){
            if(map.size()==capacity){
                // remove least used item
                map.erase(dq.back().first);
                dq.pop_back();
            }
            dq.push_front(make_pair(key, value));
            map[key] = dq.begin();
        }
        else{
            auto it = map[key];
            dq.splice(dq.begin(), dq, it);
            it->second = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */