class Solution {
public:

    /*
        recurpermute(index, ans, nums)
        --------------------------------
        index = current position to fix
        nums  = current arrangement
        ans   = stores all permutations
    */

    void recurpermute(int index, vector<vector<int>> &ans, vector<int> &nums){

        // ✅ BASE CASE:
        // If we fixed all positions, store the permutation
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }

        // 🔁 Try every element for current index
        for(int i = index; i < nums.size(); i++){

            // 👉 STEP 1: Place nums[i] at position 'index'
            swap(nums[i], nums[index]);

            // 👉 STEP 2: Recurse to fix next position
            recurpermute(index + 1, ans, nums);

            // 👉 STEP 3: Undo the swap (BACKTRACK)
            swap(nums[i], nums[index]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        // Start fixing from index 0
        recurpermute(0, ans, nums);

        return ans;
    }
};
