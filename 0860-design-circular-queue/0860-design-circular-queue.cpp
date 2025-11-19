class MyCircularQueue {
private:
    // Singly linked list node (stores value and pointer to next node)
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int v) : val(v), next(nullptr) {}
    };

    int space;       // how many free slots remain (capacity - current size)
    ListNode* left;  // left sentinel; left->next is the front element
    ListNode* right; // pointer to the last real node (rear). When empty, right == left.

public:
    // Constructor: create a queue with capacity k
    MyCircularQueue(int k) {
        space = k;               // initially k free slots
        left = new ListNode(0);  // left sentinel node (dummy)
        right = left;            // when empty, right points to left sentinel
        // left->next is implicitly nullptr => queue empty
    }

    // Insert value into the queue at the rear. Return true if succeeded.
    bool enQueue(int value) {
        if (isFull()) return false; // no free space available

        // create a new node for the value
        ListNode* cur = new ListNode(value);

        if (isEmpty()) {
            // If queue is empty, new node becomes the first element:
            // left -> cur, and cur is also the rear
            left->next = cur;
            right = cur;
        } else {
            // If queue not empty, attach new node after current rear and update rear
            right->next = cur;
            right = cur;
        }

        // use one free slot
        space--;
        return true;
    }

    // Remove the front element. Return true if succeeded.
    bool deQueue() {
        if (isEmpty()) return false; // nothing to remove

        // node to remove is left->next (first real node)
        ListNode* tmp = left->next;

        // bypass tmp: left->next points to the node after tmp
        left->next = left->next->next;

        // free memory for removed node
        delete tmp;

        // If the queue becomes empty after removal, reset right to the sentinel
        if (!left->next) {
            right = left;
        }

        // one more free slot now
        space++;
        return true;
    }

    // Return front value, or -1 if empty
    int Front() {
        return isEmpty() ? -1 : left->next->val;
    }

    // Return rear value, or -1 if empty
    int Rear() {
        return isEmpty() ? -1 : right->val;
    }

    // True if queue is empty
    bool isEmpty() {
        return left->next == nullptr; // no real nodes between sentinel and end
    }

    // True if queue has no free space
    bool isFull() {
        return space == 0;
    }
};
