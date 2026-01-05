class Solution {

    // Stores all unique subsets
    vector<vector<int>> res;

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // Step 1: Sort the array so duplicates are adjacent
        sort(nums.begin(), nums.end());

        // Step 2: Start backtracking from index 0
        backtrack(0, {}, nums);

        return res;
    }

    /*
        backtrack(i, subset, nums)
        ---------------------------
        i      : current index we are deciding on
        subset : subset built so far
        nums   : sorted input array
    */
    void backtrack(int i, vector<int> subset, vector<int>& nums) {

        // BASE CASE:
        // If we have processed all elements
        if (i == nums.size()) {
            // Store the current subset
            res.push_back(subset);
            return;
        }

        // ============================
        // CHOICE 1: TAKE nums[i]
        // ============================

        subset.push_back(nums[i]);       // include current element
        backtrack(i + 1, subset, nums);  // move to next index

        // BACKTRACK: undo the choice
        subset.pop_back();

        // ============================
        // CHOICE 2: SKIP nums[i]
        // ============================

        // Skip ALL duplicates of nums[i]
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }

        // Move to next DIFFERENT element
        backtrack(i + 1, subset, nums);
    }
};
