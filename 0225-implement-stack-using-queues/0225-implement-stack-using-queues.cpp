#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1; // main queue that will always have the stack elements
    queue<int> q2; // helper queue used during push operation

    // Constructor - nothing special to initialize
    MyStack() {}

    // PUSH operation (insert element into stack)
    void push(int x) {
        // Step 1: Move all elements from q1 to q2 temporarily
        // This is done so we can insert the new element at the "front" (top) of q1 later
        while (!q1.empty()) {
            q2.push(q1.front()); // move front element of q1 into q2
            q1.pop();
        }

        // Step 2: Push the new element into q1
        // This element should be at the front (top of the stack)
        q1.push(x);

        // Step 3: Move all elements back from q2 to q1
        // Now the new element will remain at the front of q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }

        // After this process, q1 always contains the correct stack order:
        // The most recently pushed element is at the front of q1
    }

    // POP operation (remove top element from stack)
    int pop() {
        // Since top of stack = front of q1
        int ans = q1.front();
        q1.pop(); // remove it
        return ans;
    }

    // TOP operation (get top element of stack)
    int top() {
        // Just return the front of q1
        return q1.front();
    }

    // EMPTY operation (check if stack is empty)
    bool empty() {
        return q1.empty();
    }
};

