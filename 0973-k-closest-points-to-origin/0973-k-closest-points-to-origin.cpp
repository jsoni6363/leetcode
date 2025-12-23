class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // ==================================================
        // STEP 1: Sort points based on distance from origin
        // ==================================================
        // We use a custom comparator (lambda function)
        // to compare two points 'a' and 'b'
        //
        // Distance formula (without sqrt):
        // a -> a[0]^2 + a[1]^2
        // b -> b[0]^2 + b[1]^2
        //
        // If distance of 'a' is smaller, 'a' comes first
        sort(points.begin(), points.end(),
             [](const auto& a, const auto& b) {

                 // Squared distance of point 'a'
                 int distA = a[0] * a[0] + a[1] * a[1];

                 // Squared distance of point 'b'
                 int distB = b[0] * b[0] + b[1] * b[1];

                 // Sort in increasing order of distance
                 return distA < distB;
             });

        // ==================================================
        // STEP 2: Return first 'k' points
        // ==================================================
        // Since the points are now sorted by distance,
        // the first 'k' points are the closest to origin
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
