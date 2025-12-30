class Solution {
public:
    int findMaximizedCapital(int k, int w,
                             vector<int>& profits,
                             vector<int>& capital) {

        // Max heap to store profits of projects
        // This helps us pick the MOST profitable project
        priority_queue<int> maxProfit;

        // Min heap to store projects by required capital
        // Each element = (capitalRequired, profit)
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<>
        > minCapital;

        // Step 1: Put all projects into minCapital heap
        for (int i = 0; i < capital.size(); i++) {
            minCapital.push({capital[i], profits[i]});
        }

        // Step 2: We can choose at most k projects
        for (int i = 0; i < k; i++) {

            // Move all projects we can afford into maxProfit heap
            while (!minCapital.empty() &&
                   minCapital.top().first <= w) {

                // Push profit into maxProfit heap
                maxProfit.push(minCapital.top().second);
                minCapital.pop();
            }

            // If no project is affordable, stop early
            if (maxProfit.empty()) {
                break;
            }

            // Choose the most profitable affordable project
            w += maxProfit.top();
            maxProfit.pop();
        }

        // Final maximized capital
        return w;
    }
};
