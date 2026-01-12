class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int> ans;   // to store final result

        // i runs over x-part (0 to n-1)
        for(int i = 0; i < n; i++) {
            ans.push_back(nums[i]);     // take xi
            ans.push_back(nums[i + n]); // take yi
        }

        return ans;
    }
};
