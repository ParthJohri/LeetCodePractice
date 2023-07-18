class Node{
        public:
         int key;
         int val;
         Node* next;
         Node* prev;
        public:
         Node(int k,int v){
             this->key=k;
             this->val=v;
             next=NULL;
             prev=NULL;
         }
    };
class LRUCache {
public:
    map<int,Node*> m;
    int sz;
    Node* head=new Node(0,0);
    Node* tail=new Node(0,0);
    LRUCache(int capacity) {
        head->next=tail;
        tail->prev=head;
        this->sz=capacity;
    }
    void insert(Node* curr){
        curr->next=head->next;
        head->next->prev=curr;
        curr->prev=head;
        head->next=curr;
        sz--;
        m[curr->key]=curr;
    }
    void remove(Node* curr){
        m.erase(curr->key);
        curr->next->prev=curr->prev;
        curr->prev->next=curr->next;
        sz++;
    }
    int get(int key) {
        if(m.count(key)){
            Node* n=m[key];
            remove(m[key]);
            insert(n);
            return n->val;
        }
        else{
            return -1;
        }
    }
    void put(int key, int value) {
        if(m.count(key)){
            remove(m[key]);
        }
        if(sz==0){
            remove(tail->prev);
        }
        Node* n=new Node(key,value);
        insert(n);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */