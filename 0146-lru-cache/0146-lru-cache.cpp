class LRUCache {
public:
    class Node{
        public: 
            int key;
            int val;
            Node* prev;
            Node* next;

            Node(int key, int val){
                this->key = key;
                this->val = val;
            }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int size;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        size = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addNode(Node* newnode){
        Node* temp = head -> next;

        newnode -> next = temp;
        newnode -> prev = head;

        head -> next = newnode;
        temp -> prev = newnode;
    }

    void deleteNode(Node* delnode){
        Node* prevnode = delnode -> prev;
        Node* nextnode = delnode -> next;

        prevnode -> next = nextnode;
        nextnode -> prev = prevnode;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* resNode = mp[key];
            int ans = resNode -> val;

            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);

            mp[key] = head -> next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* curr = mp[key];
            mp.erase(key);
            deleteNode(curr);
        }

        if(mp.size() == size){
            mp.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }

        addNode(new Node(key, value));
        mp[key] = head -> next;
    }
};