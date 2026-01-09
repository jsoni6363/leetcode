class Solution {
public:

    vector<vector<int>> res;   // stores all valid unique combinations

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        // Sort array so:
        // 1. duplicates are together
        // 2. easy to skip duplicates
        sort(candidates.begin(), candidates.end());

        vector<int> cur;   // current combination being built

        dfs(candidates, target, 0, cur, 0);

        return res;
    }

private:

    /*
        dfs(...)
        ------
        candidates -> given numbers
        target     -> required sum
        i          -> current index
        cur        -> current combination
        total      -> sum of elements in cur
    */
    void dfs(vector<int>& candidates,
             int target,
             int i,
             vector<int>& cur,
             int total) {

        // ✅ If sum becomes exactly target → store answer
        if (total == target) {
            res.push_back(cur);
            return;
        }

        // ❌ If sum exceeds target OR no elements left → stop
        if (total > target || i == candidates.size()) {
            return;
        }

        // =====================
        // ✅ PICK current element
        // =====================
        cur.push_back(candidates[i]);                 // take current number
        dfs(candidates, target, i + 1, cur, total + candidates[i]);  
        cur.pop_back();                               // backtrack

        // ==========================
        // 🚫 SKIP all duplicates
        // ==========================
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }

        // =========================
        // ✅ NOT PICK current element
        // =========================
        dfs(candidates, target, i + 1, cur, total);
    }
};
