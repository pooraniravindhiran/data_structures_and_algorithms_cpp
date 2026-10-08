class LRUCache {
private:
    struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k, int v):key(k), val(v){
            prev = NULL;
            next = NULL;
        }
    };
    unordered_map<int, Node*> mp;
    int capacity;
    Node* head;
    Node* tail;

    void removeNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNode(Node* node){
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity= capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        for (auto &p : mp) {
            delete p.second;
        }

        delete head;
        delete tail;
    }
    
    int get(int key) {
        // TC- O(1)
        if(mp.find(key)==mp.end())
            return -1;

        Node* node = mp[key];

        // update recency- move this node to MRU
        removeNode(node);
        addNode(node);

        return node->val;
    }
    
    void put(int key, int value) {
        // TC- O(1)
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];

            node->val = value;

            // Move to MRU
            removeNode(node);
            addNode(node);

            return;
        }

        Node* node = new Node(key, value);
        addNode(node);
        mp[key] = node;

        if(mp.size()>capacity){
            Node* lru = head->next;
            removeNode(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */