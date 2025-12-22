class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        // Keep smashing stones until only one or no stone is left
        while (stones.size() > 1) {

            // Step 1: Sort the stones in ascending order
            // After sorting:
            // smallest stone -> index 0
            // largest stone  -> last index
            sort(stones.begin(), stones.end());

            // Step 2: Take the two heaviest stones
            int heaviest = stones.back();                 // last element
            int secondHeaviest = stones[stones.size() - 2]; // second last

            // Step 3: Smash them
            int newStone = heaviest - secondHeaviest;

            // Step 4: Remove the two stones we just smashed
            stones.pop_back(); // remove heaviest
            stones.pop_back(); // remove second heaviest

            // Step 5: If there is a remaining stone, add it back
            if (newStone != 0) {
                stones.push_back(newStone);
            }
        }

        // Step 6: If no stones left, return 0
        // Otherwise return the remaining stone
        return stones.empty() ? 0 : stones[0];
    }
};
