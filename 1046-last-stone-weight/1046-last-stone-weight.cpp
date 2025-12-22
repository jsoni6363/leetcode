class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        // ============================
        // STEP 1: Create a MAX HEAP
        // ============================
        // priority_queue<int> is a max heap by default in C++
        // The largest element will always be at the top
        priority_queue<int> maxHeap;

        // Insert all stone weights into the heap
        for (int s : stones) {
            maxHeap.push(s);
        }

        // ============================
        // STEP 2: Smash stones until only one remains
        // ============================
        while (maxHeap.size() > 1) {

            // Take the heaviest stone
            int first = maxHeap.top();
            maxHeap.pop();

            // Take the second heaviest stone
            int second = maxHeap.top();
            maxHeap.pop();

            // ============================
            // STEP 3: Smash them
            // ============================
            // If both stones are equal, they cancel out
            // If not equal, push the remaining weight back
            if (first > second) {
                maxHeap.push(first - second);
            }
            // If first == second → both destroyed → do nothing
        }

        // ============================
        // STEP 4: Handle empty heap case
        // ============================
        // If heap is empty, push 0 so we can safely return top()
        maxHeap.push(0);

        // The remaining stone (or 0)
        return maxHeap.top();
    }
};
