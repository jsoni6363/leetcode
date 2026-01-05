class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // Step 1: Sort to bring duplicates together
        sort(nums.begin(), nums.end());

        // Result starts with empty subset
        vector<vector<int>> res = {{}};

        // prevIdx remembers where new subsets started last time
        int prevIdx = 0;

        for (int i = 0; i < nums.size(); i++) {

            // If current number is duplicate,
            // only extend subsets created in last step
            int idx = (i > 0 && nums[i] == nums[i - 1]) ? prevIdx : 0;

            // Save current size before adding new subsets
            prevIdx = res.size();

            // Create new subsets
            for (int j = idx; j < prevIdx; j++) {

                vector<int> subset = res[j];
                subset.push_back(nums[i]);
                res.push_back(subset);
            }
        }

        return res;
    }
};
