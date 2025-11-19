// SC- O(capacity)

class LFUCache {
private:
    int capacity;
    int minfreq; 

    struct Node{
        int key;
        int value;
        int freq;
        Node(int k, int v, int f): key(k), value(v), freq(f){}
    };

    // you need to group keys by frequencies and same freq keys should be prioritized by recency- so need a list like in LRU
    unordered_map<int, list<Node>> freqmap;

    // for O(1) lookup, similar to LRU cache, you need to map keys to iterators
    unordered_map<int, list<Node>::iterator> keytoNode;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minfreq = 0;
    }
    
    int get(int key) {
        // TC- O(1)
        // if key is not there, return -1
        if(keytoNode.count(key)==0)
            return -1;

        auto it = keytoNode[key];
        int val = it->value;
        int freq = it->freq;

        // update freq
        // remove from curr freq bucket
        freqmap[freq].erase(it);

        // if this was the only item in the list, remove that freq itself
        if(freqmap[freq].empty()){
            freqmap.erase(freq);
            if(minfreq==freq)
                minfreq++;
        }

        // add it to next freq
        freqmap[freq+1].emplace_front(key, val, freq+1);
        keytoNode[key] = freqmap[freq+1].begin();

        // return value
        return val;
    }
    
    void put(int key, int value) {
        // TC- O(1)
        // if key is new
        if(keytoNode.count(key)==0){
            // if reached capacity, remove least freq key or if tie, least recently used key
            if(keytoNode.size()==capacity){
                auto lr = freqmap[minfreq].back();
                keytoNode.erase(lr.key);
                freqmap[minfreq].pop_back();

                // if this was the only item in the list, erase list
                if(freqmap[minfreq].empty()){
                    freqmap.erase(minfreq);
                }
            }
            freqmap[1].emplace_front(key, value, 1);
            keytoNode[key] = freqmap[1].begin();
            minfreq = 1;
        }
        // if key is already present
        else{
            auto it = keytoNode[key];
            int freq = it->freq;
            it->value = value;
            get(key);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */