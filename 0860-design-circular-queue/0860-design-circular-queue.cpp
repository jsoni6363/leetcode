class MyCircularQueue {
private:

    // Underlying storage for the queue — fixed size array
    vector<int> queue;

    // Number of elements currently inside the queue
    int size;

    // Index of the front element
    int front;

    // Index of the rear element
    int rear;

    // Maximum number of elements the queue can hold
    int capacity;

public:

    // Constructor: initializes the circular queue with size k
    MyCircularQueue(int k) {
        
        // Create a vector of size k to store the queue elements
        queue = vector<int>(k);

        size = 0;      // queue starts empty
        front = 0;     // front index starts at 0
        rear = -1;     // rear starts at -1 because queue is empty
        capacity = k;  // store the maximum capacity
    }

    // Insert an element into the circular queue
    bool enQueue(int value) {
        
        // If queue already full → cannot insert
        if (isFull()) {
            return false;
        }

        // Move rear to the next position circularly
        // Using modulo ensures we wrap around when reaching last index
        rear = (rear + 1) % capacity;

        // Insert the value at the 'rear' position
        queue[rear] = value;

        // Increase the number of items
        size++;

        return true;
    }

    // Delete the front element from the circular queue
    bool deQueue() {
        
        // If queue is empty → nothing to remove
        if (isEmpty()) {
            return false;
        }

        // Move front one position forward circularly
        front = (front + 1) % capacity;

        // One element removed → decrease size
        size--;

        return true;
    }

    // Get the front item of the queue
    int Front() {
        // If empty return -1, else return element at index 'front'
        return isEmpty() ? -1 : queue[front];
    }

    // Get the last item of the queue
    int Rear() {
        // If empty return -1, else return element at index 'rear'
        return isEmpty() ? -1 : queue[rear];
    }

    // Check if queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if queue is full
    bool isFull() {
        return size == capacity;
    }
};
