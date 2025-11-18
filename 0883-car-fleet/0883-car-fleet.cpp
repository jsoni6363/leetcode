class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        // Combine position + speed so we can sort by position
        vector<pair<int,int>> cars;
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        // Sort by position DESC → closest to target first
        sort(cars.rbegin(), cars.rend());

        vector<double> stack;  // holds fleet arrival times

        for (auto &p : cars) {

            // Time for this car to reach target
            double currTime = (double)(target - p.first) / p.second;

            if (stack.empty()) {
                // First car always creates first fleet
                stack.push_back(currTime);
            }
            else {
                // Compare car’s time with last fleet’s time
                // If currTime <= last fleet time → it merges → do NOT push
                if (currTime > stack.back()) {
                    // Cannot catch up → new fleet
                    stack.push_back(currTime);
                }
                // else: currTime <= stack.back() → merges → ignore
            }
        }

        return stack.size();  // number of fleets
    }
};
