class Solution {
public:
    int findMaximizedCapital(int k, int w,
                             vector<int>& profits,
                             vector<int>& capital) {

        /*
        minCapital heap:
        ----------------
        - Stores project indices
        - Projects are ordered by their required capital (smallest first)
        - Helps us find which projects become affordable as capital increases
        */
        auto cmpCapital = [&](int a, int b) {
            return capital[a] > capital[b];   // min-heap by capital
        };

        /*
        maxProfit heap:
        ----------------
        - Stores project indices
        - Projects are ordered by their profit (largest first)
        - Helps us choose the most profitable affordable project
        */
        auto cmpProfit = [&](int a, int b) {
            return profits[a] < profits[b];   // max-heap by profit
        };

        // Min heap: projects sorted by required capital
        priority_queue<int, vector<int>, decltype(cmpCapital)> minCapital(cmpCapital);

        // Max heap: affordable projects sorted by profit
        priority_queue<int, vector<int>, decltype(cmpProfit)> maxProfit(cmpProfit);

        // Step 1: Put all project indices into minCapital heap
        for (int i = 0; i < capital.size(); i++) {
            minCapital.push(i);
        }

        // Step 2: We can choose at most k projects
        for (int i = 0; i < k; i++) {

            /*
            Move all projects that we can currently afford
            (capital requirement <= current capital w)
            from minCapital heap to maxProfit heap
            */
            while (!minCapital.empty() &&
                   capital[minCapital.top()] <= w) {

                maxProfit.push(minCapital.top());
                minCapital.pop();
            }

            /*
            If no affordable project exists,
            we cannot do any more projects
            */
            if (maxProfit.empty()) {
                break;
            }

            /*
            Choose the project with the maximum profit
            and increase our capital
            */
            int bestProject = maxProfit.top();
            maxProfit.pop();

            w += profits[bestProject];
        }

        // Final maximized capital
        return w;
    }
};
