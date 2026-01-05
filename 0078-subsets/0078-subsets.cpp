class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // This will store all subsets
        vector<vector<int>> res;

        // This stores the current subset we are building
        vector<int> subset;

        // Start recursion from index 0
        dfs(nums, 0, subset, res);

        return res;
    }

private:
    /*
        dfs(nums, i, subset, res)
        --------------------------------
        nums   : original input array
        i      : current index we are deciding on
        subset : elements chosen so far
        res    : final list of all subsets
    */
    void dfs(const vector<int>& nums, int i,
             vector<int>& subset,
             vector<vector<int>>& res) {

        // BASE CASE:
        // If we have processed all elements
        if (i == nums.size()) {
            // Current subset is complete, store it
            res.push_back(subset);
            return;
        }

        // ===============================
        // CHOICE 1: INCLUDE nums[i]
        // ===============================

        subset.push_back(nums[i]);      // take current element
        dfs(nums, i + 1, subset, res);  // move to next index

        // BACKTRACK: undo the choice
        subset.pop_back();

        // ===============================
        // CHOICE 2: EXCLUDE nums[i]
        // ===============================

        dfs(nums, i + 1, subset, res);  // move to next index
    }
};
