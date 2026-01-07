class Solution {
public:

    void recurpermute(vector<int>& nums, int freq[],
                      vector<vector<int>>& ans,
                      vector<int>& ds) {

        // Base case: one full permutation formed
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        // Try all numbers
        for (int i = 0; i < nums.size(); i++) {

            // ❌ If already used, skip
            if (freq[i] == 1) continue;

            // ❌ Skip duplicates:
            // If current number is same as previous
            // and previous was NOT used, skip it
            //if the prev is already used means placed at correct we can use but othwerwis emight miss [1,1,2] cause that wont allow to use only duplicate
            if (i > 0 && nums[i] == nums[i-1] && freq[i-1] == 0)
                continue;

            // Choose
            freq[i] = 1;
            ds.push_back(nums[i]);

            // Explore
            recurpermute(nums, freq, ans, ds);

            // Unchoose (backtrack)
            ds.pop_back();
            freq[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        // ✅ VERY IMPORTANT: sort first
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> ds;

        int freq[nums.size()];
        for (int i = 0; i < nums.size(); i++)
            freq[i] = 0;

        recurpermute(nums, freq, ans, ds);

        return ans;
    }
};
