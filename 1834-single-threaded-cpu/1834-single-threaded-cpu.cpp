class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        // Min-heap of available tasks:
        // {processingTime, index}
        // CPU picks the smallest processingTime, then smaller index
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<>
        > available;

        // Min-heap of pending (future) tasks:
        // {enqueueTime, processingTime, index}
        // Sorted by earliest enqueueTime
        priority_queue<
            array<int, 3>,
            vector<array<int, 3>>,
            greater<>
        > pending;

        int n = tasks.size();

        // Push all tasks into pending heap
        for (int i = 0; i < n; ++i) {
            pending.push({tasks[i][0], tasks[i][1], i});
        }

        vector<int> result;      // Stores execution order
        long long time = 0;      // Current CPU time

        // Continue while there are tasks either waiting or available
        while (!pending.empty() || !available.empty()) {

            // Move all tasks that have arrived by 'time' into available heap
            while (!pending.empty() && pending.top()[0] <= time) {
                auto [enqueueTime, processTime, index] = pending.top();
                pending.pop();

                // Push into available heap (sorted by processingTime)
                available.push({processTime, index});
            }

            // If no task is available, CPU is idle
            if (available.empty()) {
                // Jump time to next task's enqueueTime
                time = pending.top()[0];
                continue;
            }

            // Pick the best available task
            auto [processTime, index] = available.top();
            available.pop();

            // Execute task
            time += processTime;

            // Record execution order
            result.push_back(index);
        }

        return result;
    }
};
