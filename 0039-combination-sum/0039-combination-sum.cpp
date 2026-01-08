class Solution {
public:

    /*
        findCombinations(...)
        ---------------------
        ind     -> current index in candidates array
        target  -> remaining sum we still need to form
        ds      -> current combination being built
        ans     -> stores all valid combinations
        candidates -> given numbers
    */
    void findcombinations(int ind, int target,
                          vector<int>& ds,
                          vector<vector<int>>& ans,
                          vector<int>& candidates) {

        // ✅ BASE CASE:
        // If we have checked all elements
        if (ind == candidates.size()) {

            // If target becomes 0, current combination is valid
            if (target == 0) {
                ans.push_back(ds);
            }

            // Either way, stop further calls
            return;
        }

        // ============================
        // ✅ CHOICE 1: PICK the element
        // ============================

        // We can only pick if it does not exceed the remaining target
        if (candidates[ind] <= target) {

            // Pick current number
            ds.push_back(candidates[ind]);

            // Stay at same index because we can reuse the same number
            findcombinations(ind, target - candidates[ind], ds, ans, candidates);

            // Backtrack: remove last added element
            ds.pop_back();
        }

        // ================================
        // ✅ CHOICE 2: NOT PICK the element
        // ================================

        // Move to the next index
        findcombinations(ind + 1, target, ds, ans, candidates);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;  // final answer
        vector<int> ds;           // current combination

        // Start recursion from index 0
        findcombinations(0, target, ds, ans, candidates);

        return ans;
    }
};
