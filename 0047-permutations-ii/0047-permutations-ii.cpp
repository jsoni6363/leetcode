class Solution {
public:

    void recurpermute(int index, vector<vector<int>> &ans, vector<int> &nums){

        // Base case: all positions fixed
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }

        // Set to track values already placed at this index
        unordered_set<int> used;

        // Try every candidate for this index
        for(int i = index; i < nums.size(); i++){

            // ❌ If this value is already used at this level, skip
            if(used.find(nums[i]) != used.end())
                continue;

            // Mark this value as used for this position
            used.insert(nums[i]);

            // Choose: place nums[i] at position index
            swap(nums[i], nums[index]);

            // Explore next position
            recurpermute(index + 1, ans, nums);

            // Unchoose: backtrack
            swap(nums[i], nums[index]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;

        // Sorting is optional here but helps consistency
        // sort(nums.begin(), nums.end());

        recurpermute(0, ans, nums);
        return ans;
    }
};
