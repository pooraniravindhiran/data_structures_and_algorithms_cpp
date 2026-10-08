class LFUCache {
private:
    struct Node{
        int key;
        int val;
        int freq;
        Node* prev;
        Node* next;
        Node(int k, int v):key(k), val(v){
            freq = 1;
            prev = NULL;
            next= NULL;
        }
    };

    int capacity, min_freq;

    unordered_map<int, Node*> mp;
    
    // freq -> DLL of nodes
    unordered_map<int, Node*> freqHead;
    unordered_map<int, Node*> freqTail;

    void removeNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNode(Node* node){
        int freq = node->freq;

        // if freq is not present
        if(freqHead.find(freq)==freqHead.end()){
            freqHead[freq] = new Node(0, 0);
            freqTail[freq] = new Node(0, 0);

            freqHead[freq]-> next = freqTail[freq];
            freqTail[freq]-> prev = freqHead[freq];
        }

        Node* tail = freqTail[freq];
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
    }

    void increaseFreq(Node* node){
        // get freq
        int freq = node->freq;

        // remove node
        removeNode(node);

        // update min freq if needed
        if(min_freq==freq and freqHead[freq]->next==freqTail[freq]){
            min_freq++;
        }

        // update freq
        node->freq++;

        // add to new freq
        addNode(node);
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        min_freq = 0;
    }

    ~LFUCache(){
        for (auto &p : mp) {
            delete p.second;
        }

        for(auto &p: freqHead)
            delete p.second;

        for(auto &p: freqTail)
            delete p.second;
        
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        
        Node* node = mp[key];

        increaseFreq(node);

        // get and return val
        return node->val;
    }
    
    void put(int key, int value) {
        // if key there, update val and freq
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            node->val = value;
            increaseFreq(node);
            return;
        }

        // if not there, add it
        Node* node = new Node(key, value);
        addNode(node);
        mp[key] = node;

        // if capacity reached, evict LF/ LRU
        if(mp.size()>capacity){
            Node* lru = freqHead[min_freq]->next;
            removeNode(lru);
            mp.erase(lru->key);
            delete lru;
        }

        // update min_freq
        min_freq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */