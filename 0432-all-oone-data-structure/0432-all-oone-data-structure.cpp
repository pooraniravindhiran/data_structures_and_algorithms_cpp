class AllOne {
private:
    struct Node{
        int freq;
        unordered_set<string> keys;
        Node* prev;
        Node* next;
        Node(int f): freq(f){}
    };
    unordered_map<string, Node*> map;
    Node* head;
    Node* tail;

    void insertbucketafter(Node* newbucket, Node* currbucket){
        newbucket->prev = currbucket;
        newbucket->next = currbucket->next;
        currbucket->next->prev = newbucket;
        currbucket->next = newbucket;
    }

    void removebucket(Node* currbucket){
        currbucket->next->prev = currbucket->prev;
        currbucket->prev->next = currbucket->next;
        delete currbucket;
    }

public:
    AllOne() {
        head = new Node(INT_MIN);
        tail = new Node(INT_MAX);
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(string key) {
        // TC- O(1)

        // elem there
        if(map.count(key)){
            // delete from curr freq bucket
            auto it = map[key];
            int freq = it->freq;
            it->keys.erase(key);

            // add to freq+1 bucket
            auto nextbucket = it->next;
            if(nextbucket==tail or nextbucket->freq!=freq+1){
                Node* newbucket = new Node(freq+1);
                insertbucketafter(newbucket, it);
                nextbucket = newbucket;
            }
            nextbucket->keys.insert(key);

            // update map
            map[key] = nextbucket;

            if(it->keys.empty())
                removebucket(it);
        }

        // elem not there
        else{
            Node* nextbucket = head->next;

            // if no elements there or if freq bucket 1 not there
            if(nextbucket==tail or nextbucket->freq!=1){
                // create bucket of freq 1
                Node* newbucket = new Node(1);
                insertbucketafter(newbucket, head);
                nextbucket = newbucket;
            }
            nextbucket->keys.insert(key);
            map[key] = nextbucket;
        }
    }
    
    void dec(string key) {
        // TC- O(1)

        // remove key from curr bucket
        auto it = map[key];
        int freq = it->freq;
        if(freq==1)
            map.erase(key);
        else{
            // add to freq-1 bucket
            auto prevbucket = it->prev;
            if(prevbucket==head or prevbucket->freq!=freq-1){
                Node* newbucket = new Node(freq-1);
                insertbucketafter(newbucket, prevbucket);
                prevbucket = newbucket;
            }
            prevbucket->keys.insert(key);

            // update map
            map[key] = prevbucket;
        }

        it->keys.erase(key);
        if(it->keys.empty())
            removebucket(it);
    }
    
    string getMaxKey() {
        // TC- O(1)
        // if no elem exists, return ""
        if(tail->prev==head)
            return "";
        
        // else return elem before tail
        return *(tail->prev->keys.begin());
    }
    
    string getMinKey() {
        // TC- O(1)
        // if no elem exists, return ""
        if(head->next==tail)
            return "";
        
        // else return elem after head
        return *(head->next->keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */