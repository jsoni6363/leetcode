class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        // 'res' will store the final result string that we build step by step
        string res;

        // Max heap (priority queue)
        // Each element is a pair: (remaining_count, character)
        // The heap always gives us the character with the HIGHEST remaining count
        priority_queue<pair<int, char>> maxHeap;

        // Push only those characters that actually exist (count > 0)
        // This avoids invalid characters being used later
        if (a > 0) maxHeap.push({a, 'a'});  // push 'a' with its count
        if (b > 0) maxHeap.push({b, 'b'});  // push 'b' with its count
        if (c > 0) maxHeap.push({c, 'c'});  // push 'c' with its count

        // Keep building the string while there is at least one character available
        while (!maxHeap.empty()) {

            // Take the character with the maximum remaining count
            auto [count, ch] = maxHeap.top();
            maxHeap.pop();

            // Check if adding this character would create
            // three same characters in a row (which is NOT allowed)
            //
            // We check:
            // - string length > 1 (need at least 2 characters to compare)
            // - last character == current character
            // - second last character == current character
            if (res.size() > 1 &&
                res.back() == ch &&
                res[res.size() - 2] == ch) {

                // If we cannot use this character and there is no alternative,
                // then we must stop building the string
                if (maxHeap.empty())
                    break;

                // Take the second most frequent character from the heap
                auto [count2, ch2] = maxHeap.top();
                maxHeap.pop();

                // Add this second character to the result string
                res += ch2;

                // Decrease its count because we just used it once
                count2--;

                // If this character still has remaining count,
                // push it back into the heap
                if (count2 > 0)
                    maxHeap.push({count2, ch2});

                // Push the original blocked character back into the heap
                // (we did NOT use it, so its count stays the same)
                maxHeap.push({count, ch});
            }
            else {
                // It is safe to use this character (no 3 in a row issue)

                // Add the character to the result string
                res += ch;

                // Decrease its count
                count--;

                // If it still has remaining occurrences,
                // push it back into the heap
                if (count > 0)
                    maxHeap.push({count, ch});
            }
        }

        // Return the longest valid string we were able to build
        return res;
    }
};
