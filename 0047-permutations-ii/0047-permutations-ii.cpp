class Solution {
public:

    /*
        recurpermute(...)
        ----------------
        nums  -> original input numbers
        ds    -> current permutation being built
        ans   -> final list of unique permutations
        freq  -> marks which indices are already used (0 = not used, 1 = used)
        st    -> set to store only UNIQUE permutations
    */

    void recurpermute(vector<int>& nums, vector<int>& ds,
                      vector<vector<int>>& ans,
                      vector<int>& freq,
                      set<vector<int>>& st) {

        // ✅ BASE CASE:
        // If current permutation length == total numbers,
        // then one full permutation is formed
        if (ds.size() == nums.size()) {

            // If this permutation is NOT already in the set
            // (meaning it is unique)
            if (st.find(ds) == st.end()) {

                // Store it in the set to avoid duplicates later
                st.insert(ds);

                // Also store it in answer list
                ans.push_back(ds);
            }

            // Return to explore other possibilities
            return;
        }

        // 🔁 TRY ALL NUMBERS FOR CURRENT POSITION
        for (int i = 0; i < nums.size(); i++) {

            // ❌ If this number is already used in current permutation,
            // skip it
            if (freq[i] == 1)
                continue;

            // ✅ CHOOSE:
            // Mark this index as used
            freq[i] = 1;

            // Add this number to current permutation
            ds.push_back(nums[i]);

            // 🔍 EXPLORE:
            // Recurse to fill the next position
            recurpermute(nums, ds, ans, freq, st);

            // 🔙 UNCHOOSE (BACKTRACK):
            // Remove the last added number
            ds.pop_back();

            // Mark this index as unused again
            freq[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        // This will store final unique permutations
        vector<vector<int>> ans;

        // This stores the current permutation
        vector<int> ds;

        // Frequency array to track used elements
        vector<int> freq(nums.size(), 0);

        // ✅ Set to automatically remove duplicate permutations
        set<vector<int>> st;

        // Start recursion with empty permutation
        recurpermute(nums, ds, ans, freq, st);

        // Return all unique permutations
        return ans;
    }
};
