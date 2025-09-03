class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // --- Approach (O(N^2) Optimization) ---
        // 1. Sort the points: We sort primarily by x-coordinate ascending. If x-coordinates
        //    are the same, we sort by y-coordinate descending. This creates a predictable
        //    processing order from left to right, top to bottom.
        // 2. Iterate through pairs: For each point 'a' (our upper-left candidate),
        //    we scan all subsequent points 'b' (our lower-right candidates).
        // 3. The "Highest Wall" trick: Instead of a third loop, we just keep track of the
        //    highest y-coordinate of a valid partner found so far for 'a'. A new point 'b'
        //    can only be a valid partner if it's "higher" than that wall, ensuring no
        //    previous point is inside the new rectangle.

        int n = points.size();
        int count = 0;

        sort(points.begin(), points.end(), [](const vector<int>& p1, const vector<int>& p2) {
            if (p1[0] != p2[0]) {
                return p1[0] < p2[0]; 
            }
            return p1[1] > p2[1];
        });

        // Step 2: Iterate through each point, treating it as the upper-left corner 'a'.
        for (int i = 0; i < n; ++i) {
            const auto& a = points[i];
            
            // This is our "highest wall".
            int max_y = INT_MIN; 

            // Iterate through all subsequent points, treating them as potential lower-right corners 'b'.
            for (int j = i + 1; j < n; ++j) {
                const auto& b = points[j];

                // Check if 'b' is a potential partner (i.e., it's in the lower-right quadrant of 'a').
                // Because of our sort, b[0] >= a[0] is already guaranteed.
                if (b[1] <= a[1]) {
                    
                    // Step 3: Apply the "highest wall" trick.
                    // A valid pair is formed only if 'b' is higher than any previous
                    // valid partner we found for 'a'. This guarantees the rectangle is empty.
                    if (b[1] > max_y) {
                        // We found a valid pair, so do count++
                        count++;
                        
                        // Update the wall to the y-coordinate of our new partner.
                        max_y = b[1];
                    }
                }
            }
        }
        return count;
    }
};

