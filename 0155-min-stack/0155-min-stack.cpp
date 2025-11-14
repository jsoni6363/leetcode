#include <stack>
#include <iostream>
using namespace std;

class MinStack {
public:
    stack<int> s;       // main stack (stores all elements)
    stack<int> minS;    // helper stack (stores minimum at each level)

    MinStack() {}

    // -------------------------------
    // PUSH operation
    // -------------------------------
    void push(int val) {
        // Always push the element in main stack
        s.push(val);

        // If minS is empty, this element is the current minimum
        if (minS.empty()) {
            minS.push(val);
        }
        // Else, compare with the current minimum (top of minS)
        else {
            if (val < minS.top()) {
                // If new value is smaller, push it as new minimum
                minS.push(val);
            } else {
                // Otherwise, push the same previous minimum again
                minS.push(minS.top());
            }
        }
    }

    // -------------------------------
    // POP operation
    // -------------------------------
    void pop() {
        // Remove one element from both stacks
        if (!s.empty()) {
            s.pop();
            minS.pop();
        }
    }

    // -------------------------------
    // TOP operation
    // -------------------------------
    int top() {
        if (!s.empty()) {
            return s.top();  // return top element
        }
        return -1;  // if empty (shouldn’t happen as per constraints)
    }

    int getMin() {
        if (!minS.empty()) {
            return minS.top();  // top of minS is the current minimum
        }
        return -1;  // if empty 
    }
};
