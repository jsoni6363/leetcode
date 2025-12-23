class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // ==================================================
        // STEP 1: Create a MAX HEAP
        // ==================================================
        // Heap stores elements in the form:
        // {distance_from_origin, {x, y}}
        //
        // priority_queue in C++ is a MAX HEAP by default,
        // meaning the element with the largest distance
        // will be at the top
        priority_queue<pair<int, pair<int, int>>> maxHeap;

        // ==================================================
        // STEP 2: Iterate through all points
        // ==================================================
        for (auto& point : points) {

            // Calculate squared distance from origin
            // (no sqrt needed because ordering is preserved)
            int dist = point[0] * point[0] + point[1] * point[1];

            // Push current point into the heap
            maxHeap.push({dist, {point[0], point[1]}});

            // ==================================================
            // STEP 3: Maintain heap size = k
            // ==================================================
            // If heap size exceeds k,
            // remove the farthest point (heap top)
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        // ==================================================
        // STEP 4: Extract k closest points from heap
        // ==================================================
        vector<vector<int>> res;

        while (!maxHeap.empty()) {

            // Get the point coordinates from heap
            res.push_back({
                maxHeap.top().second.first,   // x-coordinate
                maxHeap.top().second.second   // y-coordinate
            });

            // Remove the extracted point
            maxHeap.pop();
        }

        // ==================================================
        // STEP 5: Return result
        // ==================================================
        // Order does NOT matter as per problem statement
        return res;
    }
};
