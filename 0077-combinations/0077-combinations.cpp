class Solution {
public:
    void backtrack(int start,vector<int>& ds,int n,int k,vector<vector<int>>& ans){
       if(ds.size()==k){
        ans.push_back(ds);
        return ;
       }

       for(int num=start;num<=n;num++){
        ds.push_back(num);
        backtrack(num+1,ds,n,k,ans);
        ds.pop_back();
       }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        backtrack(1,ds,n,k,ans);
        return ans;
    }

};