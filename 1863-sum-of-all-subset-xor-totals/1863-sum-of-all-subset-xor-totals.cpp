class Solution {
public:
    int result = 0;

    // Recursive function to generate subsets
    void backtrack(vector<int>& nums, int index, int currentXor) {

        // Add XOR of current subset to result
        result += currentXor;

        // Try taking each element starting from 'index'
        for (int i = index; i < nums.size(); i++) {

            // Include nums[i] in subset and move ahead
            backtrack(nums, i + 1, currentXor ^ nums[i]);
        }
    }

    int subsetXORSum(vector<int>& nums) {

        // Start with index = 0 and XOR = 0 (empty subset)
        backtrack(nums, 0, 0);

        return result;
    }
};
