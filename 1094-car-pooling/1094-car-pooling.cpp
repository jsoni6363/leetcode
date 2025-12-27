class Solution {
public:
    static bool compare(vector<int>&a , vector<int>& b){
        return a[1]<b[1];
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
         // Step 1: Sort trips by starting location
        // trips[i][1] is the start point
        sort(trips.begin(),trips.end(),compare);

        // Min heap to store ongoing trips
        // Each element = {endLocation, numberOfPassengers}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > minHeap;

        // Current number of passengers in the car
        int currentPassengers = 0;

        // Step 2: Go through each trip
        for (int i = 0; i < trips.size(); i++) {

            int passengers = trips[i][0];
            int start = trips[i][1];
            int end = trips[i][2];

            // Step 3: Remove passengers who have already reached destination
            if (!minHeap.empty()) {
                while (!minHeap.empty() && minHeap.top().first <= start) {
                    currentPassengers = currentPassengers - minHeap.top().second;
                    minHeap.pop();
                }
            }

            // Step 4: Pick up new passengers
            currentPassengers = currentPassengers + passengers;

            // Step 5: Check if capacity is exceeded
            if (currentPassengers > capacity) {
                return false;
            }

            // Step 6: Add this trip to heap
            // so we know when these passengers will leave
            minHeap.push({end, passengers});
        }

        // If capacity was never exceeded
        return true;
    }
};