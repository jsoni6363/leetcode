class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        int n = asteroids.size();

        // j will act like the "top" of our stack
        // j = -1 means the stack is empty
        int j = -1;

        // Loop through each asteroid one by one
        for (int& a : asteroids) {

            // While there is a possibility of collision:
            // j >= 0          → there is something in our stack
            // asteroids[j] > 0 → the last asteroid is moving RIGHT
            // a < 0           → current asteroid is moving LEFT
            // Only (RIGHT →) facing (← LEFT) can collide
            while (j >= 0 && asteroids[j] > 0 && a < 0) {

                // Compare the last asteroid (right-moving)
                // with the current left-moving asteroid.
                if (asteroids[j] > abs(a)) {
                    // Case 1: Right-moving asteroid is bigger
                    // The new left-moving asteroid (a) explodes.
                    a = 0;        // mark a as dead
                    break;       // no more comparisons needed
                }
                else if (asteroids[j] == abs(a)) {
                    // Case 2: Both asteroids are same size
                    // BOTH explode.
                    j--;         // remove the right-moving asteroid
                    a = 0;       // current asteroid also dies
                    break;       // collision resolved
                }
                else {
                    // Case 3: Left-moving asteroid is bigger
                    // The right-moving asteroid explodes.
                    j--;        // pop the last asteroid in our "stack"
                    // DO NOT break!
                    // Because this left-moving asteroid (a)
                    // might collide with more previous ones.
                }
            }

            // If current asteroid is still alive (not destroyed):
            if (a != 0) {
                // Push asteroid into "stack" by moving j forward
                // asteroids[++j] assigns new value to the next valid slot
                asteroids[++j] = a;
            }
        }

        // Resize array to include only the surviving asteroids
        asteroids.resize(j + 1);

        // Return the final state
        return asteroids;
    }
};
