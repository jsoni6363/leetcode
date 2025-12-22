class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        // ============================
        // STEP 1: Sort stones initially
        // ============================
        // After sorting:
        // smallest stone -> index 0
        // largest stone  -> index n-1
        sort(stones.begin(), stones.end());

        // 'n' represents number of active stones
        int n = stones.size();

        // ============================
        // STEP 2: Smash stones while more than one exists
        // ============================
        while (n > 1) {

            // Take the two largest stones
            int heaviest = stones[n - 1];
            int secondHeaviest = stones[n - 2];

            // Smash them
            int cur = heaviest - secondHeaviest;

            // Remove the two stones logically
            n -= 2;

            // ============================
            // STEP 3: Insert remaining stone (if any)
            // ============================
            if (cur > 0) {

                // Find the correct position to insert 'cur'
                // so that stones[0..n-1] remains sorted

                int l = 0, r = n;

                // Binary search for insertion position
                while (l < r) {
                    int mid = (l + r) / 2;

                    if (stones[mid] < cur) {
                        l = mid + 1;
                    } else {
                        r = mid;
                    }
                }

                // 'pos' is the index where 'cur' should be inserted
                int pos = l;

                // Expand vector by one space
                stones.push_back(0);

                // Shift elements right to make space
                for (int i = n + 1; i > pos; i--) {
                    stones[i] = stones[i - 1];
                }

                // Insert the new stone
                stones[pos] = cur;

                // Increase active stone count
                n++;
            }
        }

        // ============================
        // STEP 4: Return answer
        // ============================
        // If one stone remains, return it
        // Else return 0
        return n > 0 ? stones[0] : 0;
    }
};
