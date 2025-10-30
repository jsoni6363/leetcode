class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n=nums.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            int moreneeded=target-nums[i];
            if(mpp.find(moreneeded)!=mpp.end()){
                ans.push_back(i);
                ans.push_back(mpp[moreneeded]);
                return ans;
            }
            mpp[nums[i]]=i;
        }
        return {-1,-1};
    }
};
