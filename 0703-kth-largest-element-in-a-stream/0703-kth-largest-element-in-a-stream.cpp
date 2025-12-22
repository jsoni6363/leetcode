class KthLargest {
private:

    // Min heap that stores ONLY the k largest elements
    // The smallest element in this heap will be the k-th largest overall
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Stores the value of k
    int k;

public:

    // ============================
    // CONSTRUCTOR
    // ============================
    KthLargest(int k, vector<int>& nums) {

        // Save k
        this->k = k;

        // Insert initial numbers into the heap
        for (int num : nums) {

            // Step 1: Push the number into the heap
            minHeap.push(num);

            // Step 2: If heap size exceeds k,
            // remove the smallest element
            // This ensures heap always has ONLY k largest elements
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }

    // ============================
    // ADD FUNCTION
    // ============================
    int add(int val) {

        // Step 1: Add the new value to the heap
        minHeap.push(val);

        // Step 2: If heap size becomes greater than k,
        // remove the smallest element
        if (minHeap.size() > k) {
            minHeap.pop();
        }

        // Step 3: The top of the min heap
        // is the k-th largest element
        return minHeap.top();
    }
};
