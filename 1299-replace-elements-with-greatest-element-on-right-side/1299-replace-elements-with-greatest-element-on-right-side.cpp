class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            int rightmax=-1;
            for(int j=i+1;j<n;j++){
                rightmax=max(arr[j],rightmax);
            }
            arr[i]=rightmax;
        }
        return arr;
    }
};