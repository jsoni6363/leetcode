class Solution {
public:
    string reorganizeString(string s) {

        // Step 1: Count frequency of each character
        // freq[0] -> 'a', freq[1] -> 'b', ..., freq[25] -> 'z'
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Step 2: Create a max heap (priority queue)
        // Each element is: (count, character)
        // The character with the highest count comes out first
        priority_queue<pair<int, char>> maxHeap;

        // Push all characters with count > 0 into the heap
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                maxHeap.push({freq[i], char('a' + i)});
            }
        }

        // Result string
        string result = "";

        // 'prev' stores the previously used character
        // We keep it out of the heap for one step
        pair<int, char> prev = {0, '#'};  // {remainingCount, character}

        // Step 3: Build the result string
        while (!maxHeap.empty() || prev.first > 0) {

            // If heap is empty but we still have a previous character left,
            // it means we cannot place it without repeating
            if (maxHeap.empty() && prev.first > 0) {
                return "";  // impossible to reorganize
            }

            // Take the character with the highest remaining count
            auto top = maxHeap.top();
            maxHeap.pop();

            int count = top.first;
            char ch = top.second;

            // Add this character to the result
            result += ch;
            count--;

            // If previous character still has remaining count,
            // push it back into the heap
            if (prev.first > 0) {
                maxHeap.push(prev);
            }

            // Set current character as previous
            prev = {count, ch};
        }

        return result;
    }
};
