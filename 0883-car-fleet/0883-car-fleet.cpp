class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();  
        // Number of cars

        // STEP 1: Combine position[i] and speed[i] into a single structure
        // so that we can sort cars by position while keeping their speed attached.
        vector<pair<int, int>> cars;  // each element = {position, speed}

        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        // STEP 2: Sort cars by POSITION in DESCENDING order.
        //
        // Why descending?
        // We want to process cars starting from the one CLOSEST to the target.
        // A car can only catch the car IN FRONT of it, never behind.
        //
        // Example: positions = [7, 4, 1, 0] (closest → farthest)
        sort(cars.rbegin(), cars.rend());

        // We will count fleets using the "time to reach target".
        // The first (front-most) car always forms at least 1 fleet.
        int fleets = 1;

        // STEP 3: Compute time of the first (closest) car.
        //
        // Time = distance / speed = (target - position) / speed
        //
        // This is the time the FRONT fleet will take to reach the destination.
        double prevTime = (double)(target - cars[0].first) / cars[0].second;

        // STEP 4: Process remaining cars from front → back
        for (int i = 1; i < n; i++) {

            // Calculate time for current car to reach target
            double currTime = (double)(target - cars[i].first) / cars[i].second;

            // ❗ LOGIC:
            //
            // If currTime > prevTime:
            // ➜ The car behind is SLOWER or takes MORE TIME
            // ➜ It CANNOT catch up to the fleet in front
            // ➜ Therefore it forms its OWN fleet → fleets++
            //
            // If currTime <= prevTime:
            // ➜ The car behind ARRIVES EARLIER or AT SAME TIME
            // ➜ It WILL catch the fleet in front BEFORE or AT the target
            // ➜ It joins the same fleet → do NOT increment fleets
            if (currTime > prevTime) {
                fleets++;            // new fleet is formed
                prevTime = currTime; // this fleet now becomes the "front" fleet
            }

            // If currTime <= prevTime:
            // → Do nothing, because it becomes part of the same fleet.
        }

        // Number of fleets that will reach the destination
        return fleets;
    }
};
