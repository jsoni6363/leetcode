class Solution {
public:

    // Helper function to sort trips by start location
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];  // sort by startLocation
    }

    bool carPooling(vector<vector<int>>& trips, int capacity) {

        // Step 1: Sort trips based on starting point
        sort(trips.begin(), trips.end(), compare);

        // Step 2: Go through each trip one by one
        for (int i = 0; i < trips.size(); i++) {

            // Passengers of current trip
            int currentPassengers = trips[i][0];

            // Step 3: Check all previous trips
            for (int j = 0; j < i; j++) {

                // If previous trip has NOT ended yet,
                // its passengers are still in the car
                if (trips[j][2] > trips[i][1]) {
                    currentPassengers += trips[j][0];
                }
            }

            // Step 4: Check capacity
            if (currentPassengers > capacity) {
                return false;  // capacity exceeded
            }
        }

        // If we never exceeded capacity
        return true;
    }
};
