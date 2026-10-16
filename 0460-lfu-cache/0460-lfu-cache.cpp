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
            next = NULL;
        }
    };

    int capacity;
    int min_freq;
    unordered_map<int, Node*> mp;
    unordered_map<int, Node*> heads;
    unordered_map<int, Node*> tails;

    void add_node(Node* node){
        int freq = 1;
        if(tails.find(freq)==tails.end()){
            heads[freq] = new Node(-1, -1);
            tails[freq] = new Node(-1, -1);
            heads[freq]->next = tails[freq];
            tails[freq]->prev = heads[freq];
        }
        tails[freq]->prev->next = node;
        node->prev = tails[freq]->prev;
        node->next = tails[freq];
        tails[freq]->prev = node;
    }

    void remove_node(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void update_node(Node* node){
        int freq = node->freq;

        // remove node
        remove_node(node);

        // if only node in freq, remove freq and update min_freq
        if (heads[freq]->next == tails[freq]){
            heads.erase(freq);
            tails.erase(freq);
            if(min_freq==freq)
                min_freq = min_freq+1;
        }

        // inc freq
        node->freq ++;

        // add to new freq
        int newFreq = node->freq;

        if (heads.find(newFreq) == heads.end()) {
            heads[newFreq] = new Node(0, 0);
            tails[newFreq] = new Node(0, 0);

            heads[newFreq]->next = tails[newFreq];
            tails[newFreq]->prev = heads[newFreq];
        }

        Node* tail = tails[newFreq];
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        min_freq = 0;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        
        Node* node = mp[key];

        // update freq and recency and min_freq
        update_node(node);

        return node->val;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];

            node->val = value;

            // update freq and recency and min_freq
            update_node(node);

            return;
        }

        Node* node = new Node(key, value);
        // add node
        add_node(node);
        mp[key] = node;

        if(mp.size()>capacity){
            // remove lru from list and mp and delete it
            Node* lru = heads[min_freq]->next;
            remove_node(lru);
            mp.erase(lru->key);
            delete(lru);
        }
        min_freq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */