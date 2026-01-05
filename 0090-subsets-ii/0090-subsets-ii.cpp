class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        vector<vector<int>> ans={{}};

        int startindex=0;
        int endindex=0;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1])
            startindex=endindex;
            else
            startindex=0;

            endindex=ans.size();
            for(int j=startindex;j<endindex;j++){
                    vector<int> subset=ans[j];
                    subset.push_back(nums[i]);
                    ans.push_back(subset);
            }
        }
        return ans;
    }
};
