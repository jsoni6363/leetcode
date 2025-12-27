class Solution {
public:
    static bool compare(vector<int>&a , vector<int>& b){
        return a[1]<b[1];
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),compare);
        int n=trips.size();
        for(int i=0;i<n;i++){
            int currPass=trips[i][0];

            for(int j=0;j<i;j++){
                if(trips[j][2]>trips[i][1])
                currPass+=trips[j][0];
            }
            if(currPass>capacity)
            return false;
        }
        return true;
    }
};