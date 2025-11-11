// A node of our doubly linked list
class Node {
public:
    int key;     // key of cache entry
    int val;     // value of cache entry
    Node* prev;  // pointer to previous node
    Node* next;  // pointer to next node

    // Constructor to create a new node
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int cap;  // maximum capacity of cache

    // Hash map: key -> pointer to node in the list
    // Allows O(1) access to a node
    unordered_map<int, Node*> cache;

    // Dummy boundary nodes for the doubly linked list
    // left = Least Recently Used (LRU side)
    // right = Most Recently Used (MRU side)
    Node* left;
    Node* right;

    // ✅ Remove a node from the doubly linked list in O(1)
    void remove(Node* node) {
        Node* prev = node->prev;  // node before the current one
        Node* nxt = node->next;   // node after the current one

        // Connect previous -> next
        prev->next = nxt;

        // Connect next -> previous
        nxt->prev = prev;
    }

    // ✅ Insert a node at the right end (MRU position) in O(1)
    void insert(Node* node) {
        Node* prev = right->prev;  // last real node in list

        // Connect previous node to the new node
        prev->next = node;
        node->prev = prev;

        // Connect new node to right dummy
        node->next = right;
        right->prev = node;
    }

public:
    // Constructor initializes capacity and empty list
    LRUCache(int capacity) {
        cap = capacity;

        // Create dummy boundary nodes
        left = new Node(0, 0);
        right = new Node(0, 0);

        // Initially list is empty: left <--> right
        left->next = right;
        right->prev = left;
    }

    // ✅ Get value for a key
    int get(int key) {
        // If key exists in cache
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];

            // Move this node to MRU position because it's used now
            remove(node);
            insert(node);

            return node->val;
        }
        return -1; // key not found
    }

    // ✅ Put (key, value) into cache
    void put(int key, int value) {
        // If key already exists, remove old node first
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }

        // Create a new node for the key/value
        Node* newNode = new Node(key, value);

        // Add to hash map
        cache[key] = newNode;

        // Put this node at MRU position
        insert(newNode);

        // If cache exceeds capacity, remove LRU item
        if (cache.size() > cap) {
            Node* lru = left->next; // left->next is least recently used
            remove(lru);            // remove from list
            cache.erase(lru->key);  // remove from hash map
            delete lru;             // free memory
        }
    }
};
