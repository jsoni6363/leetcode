class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        int n = tasks.size();

        // --------------------------------------------------
        // Step 1: Attach original index to each task
        // Each task becomes:
        // [enqueueTime, processingTime, originalIndex]
        // --------------------------------------------------
        for (int i = 0; i < n; ++i) {
            tasks[i].push_back(i);
        }

        // --------------------------------------------------
        // Step 2: Sort tasks by enqueueTime
        // Because of vector ordering, sorting happens as:
        // 1) enqueueTime
        // 2) processingTime (if tie)
        // 3) index (if tie)
        // --------------------------------------------------
        sort(tasks.begin(), tasks.end());

        // Result vector to store execution order
        vector<int> res;

        // --------------------------------------------------
        // Min-heap for available tasks
        // Stores: {processingTime, index}
        // CPU always picks task with smallest processingTime
        // --------------------------------------------------
        priority_queue<
            array<int, 2>,
            vector<array<int, 2>>,
            greater<>
        > minHeap;

        // Pointer to iterate through sorted tasks
        int i = 0;

        // Current CPU time starts at first task's enqueue time
        long long time = tasks[0][0];

        // --------------------------------------------------
        // Main simulation loop
        // Continue while tasks are remaining or heap is not empty
        // --------------------------------------------------
        while (!minHeap.empty() || i < n) {

            // --------------------------------------------------
            // Add all tasks that have arrived by current time
            // --------------------------------------------------
            while (i < n && time >= tasks[i][0]) {
                // Push {processingTime, index} into heap
                minHeap.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            // --------------------------------------------------
            // If no task is available, CPU is idle
            // Jump time to next task's enqueue time
            // --------------------------------------------------
            if (minHeap.empty()) {
                time = tasks[i][0];
            }
            else {
                // --------------------------------------------------
                // Pick the task with smallest processing time
                // --------------------------------------------------
                auto [procTime, index] = minHeap.top();
                minHeap.pop();

                // Execute the task
                time += procTime;

                // Record execution order
                res.push_back(index);
            }
        }

        return res;
    }
};
