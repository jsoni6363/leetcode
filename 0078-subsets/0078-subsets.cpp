class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        // Result initially contains only ONE subset: empty subset
        vector<vector<int>> res = { {} };

        // Loop through each number in nums
        for (int num : nums) {

            // Current number of subsets
            int size = res.size();

            // For each existing subset
            for (int i = 0; i < size; i++) {

                // Make a copy of the current subset
                vector<int> subset = res[i];

                // Add current number to it
                subset.push_back(num);

                // Add the new subset to result
                res.push_back(subset);
            }
        }

        return res;
    }
};
