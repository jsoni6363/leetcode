class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        for(int x:matchsticks)
        sum+=x;

        if(sum%4!=0) return false;
        vector<int> sides(4,0);
        int len=sum/4;
        sort(matchsticks.rbegin(),matchsticks.rend());
        return recur(0,matchsticks,sides,len);
    }
    bool recur(int index,vector<int>& matchsticks,vector<int>& sides,int length){
        if(index==matchsticks.size()){
            return true;
        }

        for(int i=0;i<4;i++){
            if(sides[i]+matchsticks[index]<=length){
                sides[i]+=matchsticks[index];
                if(recur(index+1,matchsticks,sides,length)){
                    return true;
                }
                sides[i]-=matchsticks[index];
            }
        }

        return false;
    }
};