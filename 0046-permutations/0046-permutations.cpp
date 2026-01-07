class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        // This will store all permutations
        vector<vector<int>> perms;

        // Start with one empty permutation: { }
        perms.push_back(vector<int>());

        // Take numbers one by one from nums
        for (int idx = 0; idx < nums.size(); idx++) {

            int num = nums[idx];

            // This will store new permutations after inserting num
            vector<vector<int>> new_perms;

            // Go through each existing permutation
            for (int j = 0; j < perms.size(); j++) {

                vector<int> current = perms[j];

                // Insert num into every possible position
                for (int i = 0; i <= current.size(); i++) {

                    // Make a copy of current permutation
                    vector<int> temp = current;

                    // Insert num at index i
                    temp.insert(temp.begin() + i, num);

                    // Store this new permutation
                    new_perms.push_back(temp);
                }
            }

            // Update perms to newly formed permutations
            perms = new_perms;
        }

        // perms now contains all permutations
        return perms;
    }
};
