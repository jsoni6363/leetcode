class Solution {
public:

    /*
        backtrack(start)
        ----------------
        start -> number from where we are allowed to pick next
        curr  -> current combination being built
    */

    void backtrack(int start, int n, int k,
                   vector<int>& curr,
                   vector<vector<int>>& ans) {

        // ✅ If we have picked k numbers, store the combination
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        // ✅ Try all possible numbers from 'start' to 'n'
        for (int num = start; num <= n; num++) {

            // pick
            curr.push_back(num);

            // move forward (next number must be bigger)
            backtrack(num + 1, n, k, curr, ans);

            // backtrack (remove last picked number)
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> ans;
        vector<int> curr;

        // start picking from 1
        backtrack(1, n, k, curr, ans);

        return ans;
    }
};
