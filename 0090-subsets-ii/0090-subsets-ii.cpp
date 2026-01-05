class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // Sort so duplicates come together
        sort(nums.begin(), nums.end());

        // Result starts with empty subset
        vector<vector<int>> res = {{}};

        // This tells from where to start adding new subsets
        int startIndex = 0;

        for (int i = 0; i < nums.size(); i++) {

            int endIndex = res.size();  // current size of result

            // IF current number is a duplicate
            if (i > 0 && nums[i] == nums[i - 1]) {
                // Only use subsets added in previous step
                startIndex = startIndex;
            }
            // ELSE current number is NOT a duplicate
            else {
                // Use all existing subsets
                startIndex = 0;
            }

            // Save current size before adding new subsets
            int oldSize = res.size();

            // Add current number to required subsets
            for (int j = startIndex; j < oldSize; j++) {
                vector<int> subset = res[j];
                subset.push_back(nums[i]);
                res.push_back(subset);
            }

            // Update startIndex for next iteration
            startIndex = oldSize;
        }

        return res;
    }
};
