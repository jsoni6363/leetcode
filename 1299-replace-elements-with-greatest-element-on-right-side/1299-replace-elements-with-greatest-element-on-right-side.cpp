class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        int rightmax=-1;
        for(int i=n-1;i>=0;i--){
              int curr = arr[i];          // store original value
            arr[i] = rightmax;          // replace with max on right
            rightmax = max(rightmax, curr); // update right max
        }
        return arr;
    }
};