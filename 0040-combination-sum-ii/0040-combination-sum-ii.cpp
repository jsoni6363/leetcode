class Solution {
public:

    /*
        findcombinations(...)
        ---------------------
        ind        -> index from where we are allowed to choose numbers
        ds         -> "data structure" (current combination being built)
        ans        -> stores all valid unique combinations
        target    -> remaining sum we need to form
        candidates-> given array (already sorted)
    */
    void findcombinations(int ind,
                          vector<int>& ds,
                          vector<vector<int>>& ans,
                          int target,
                          vector<int>& candidates) {

        // ✅ BASE CASE:
        // If target becomes 0, we found a valid combination
        if (target == 0) {
            ans.push_back(ds);   // store the current combination
            return;              // stop this path
        }

        // ✅ Try all options starting from index 'ind'
        for (int i = ind; i < candidates.size(); i++) {

            // 🚫 Skip duplicates at the same recursion level
            // Example: [1,1,2]
            // if first 1 is not picked, second 1 should not start a new branch
            if (i > ind && candidates[i] == candidates[i - 1]) 
                continue;

            // ⛔ If current number is greater than remaining target
            // no need to continue (array is sorted)
            if (candidates[i] > target) 
                break;

            // =====================
            // ✅ PICK the element
            // =====================
            ds.push_back(candidates[i]);

            // Move to next index (i + 1) because each element
            // can be used only once
            findcombinations(i + 1, ds, ans, target - candidates[i], candidates);

            // ==========================
            // 🔙 BACKTRACK (remove last)
            // ==========================
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        // ✅ Sort to:
        // 1. handle duplicates
        // 2. allow early stopping using break
        sort(candidates.begin(), candidates.end());

        vector<int> ds;                 // current combination
        vector<vector<int>> ans;        // final answer

        // Start recursion from index 0
        findcombinations(0, ds, ans, target, candidates);

        return ans;
    }
};
