class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
        vector<int> res(n, 0);

        // stack stores INDEXES of days
        stack<int> st;

        // Start from the last day and move backwards
        for (int i = n - 1; i >= 0; i--) {

            // Remove all days that are NOT warmer than today
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            // If stack is not empty → next warmer day exists
            if (!st.empty()) {
                res[i] = st.top() - i;   // distance to warmer day
            }
            else {
                res[i] = 0;             // no warmer day
            }

            // Push today's index to the stack
            st.push(i);
        }

        return res;
    }
};
