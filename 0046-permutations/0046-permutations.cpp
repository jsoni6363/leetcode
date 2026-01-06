class Solution {
public:

    /*
        recurpermute(...)
        -----------------
        nums : original numbers
        freq : keeps track of used elements
        ans  : stores all permutations
        ds   : current permutation being built
    */
    void recurpermute(vector<int>& nums, int freq[],
                      vector<vector<int>>& ans,
                      vector<int> &ds) {

        // BASE CASE:
        // If current permutation size equals nums size,
        // we formed one full permutation
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        // Try placing each number at current position
        for (int i = 0; i < nums.size(); i++) {

            // If this number is not used yet
            if (!freq[i]) {

                // Mark it as used
                freq[i] = 1;

                // Pick the number
                ds.push_back(nums[i]);

                // Recurse to fill next position
                recurpermute(nums, freq, ans, ds);

                // BACKTRACK:
                // Remove the number
                ds.pop_back();

                // Mark it as unused
                freq[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;   // stores all permutations
        vector<int> ds;            // current permutation

        // Frequency array (0 = not used, 1 = used)
        int freq[nums.size()];
        for (int i = 0; i < nums.size(); i++)
            freq[i] = 0;

        // Start recursion
        recurpermute(nums, freq, ans, ds);

        return ans;
    }
};
