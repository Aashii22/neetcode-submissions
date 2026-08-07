class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

    Node(int k, int v): key(k), val(v), prev(NULL), next(NULL) {};
};
class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> mp;
    Node* left;
    Node* right;
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(-1, -1);
        right = new Node(-1, -1);
        left->next = right;
        right->prev = left;
    }

    void update(int key, int val){
        Node* curr;
        if(mp.find(key)!=mp.end()){
            curr = mp[key];
            curr->val = val;
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }
        else{
            curr = new Node(key, val);
            mp[key] = curr;
            cap--;
        }

        curr->next = left->next;
        left->next->prev = curr;
        curr->prev = left;
        left->next = curr;

        if(cap<0){
            remove();
        }
    }

    void remove(){
        mp.erase(right->prev->key);
        right->prev = right->prev->prev;
        right->prev->next = right;
        cap++;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            update(key, mp[key]->val);

            return mp[key]->val;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        update(key, value);
    }
};