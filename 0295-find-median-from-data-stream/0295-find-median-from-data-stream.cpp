class MedianFinder {

    // Max heap to store the smaller half of numbers
    // Top element = largest among the smaller half
    priority_queue<int> smallHeap;

    // Min heap to store the larger half of numbers
    // Top element = smallest among the larger half
    priority_queue<int, vector<int>, greater<int>> largeHeap;

public:
    MedianFinder() {}

    // Adds a number into the data structure
    void addNum(int num) {

        // Step 1: Always insert into smallHeap first
        smallHeap.push(num);

        // Step 2: Fix ordering
        // If largest in smallHeap is greater than smallest in largeHeap,
        // move it to largeHeap
        if (!largeHeap.empty() && smallHeap.top() > largeHeap.top()) {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }

        // Step 3: Balance sizes (smallHeap too big)
        if (smallHeap.size() > largeHeap.size() + 1) {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }

        // Step 4: Balance sizes (largeHeap too big)
        if (largeHeap.size() > smallHeap.size() + 1) {
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {

        // If both heaps have same size → even count
        if (smallHeap.size() == largeHeap.size()) {
            return (smallHeap.top() + largeHeap.top()) / 2.0;
        }

        // If smallHeap has more elements
        if (smallHeap.size() > largeHeap.size()) {
            return smallHeap.top();
        }

        // If largeHeap has more elements
        return largeHeap.top();
    }
};
