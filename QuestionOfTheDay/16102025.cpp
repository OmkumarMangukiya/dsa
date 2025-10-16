// https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/?envType=daily-question&envId=2025-10-16
class Solution {
public:
    int findSmallestInteger(std::vector<int>& nums, int value) {
        // Create a frequency map for remainders.
        // The size is `value` to store counts for remainders 0, 1, ..., value-1.
        std::vector<int> counts(value, 0);

        // Calculate the remainder for each number and update the frequency map.
        for (int num : nums) {
            // The formula `(num % value + value) % value` ensures the remainder
            // is always non-negative, which is crucial for negative numbers.
            int remainder = (num % value + value) % value;
            counts[remainder]++;
        }

        // Find the smallest non-negative integer `k` (also known as MEX - Minimum Excluded value)
        // that cannot be constructed from the numbers in `nums`.
        // We can form `k` if we have an available number in `nums` whose remainder is `k % value`.
        for (int k = 0; ; ++k) {
            // The remainder needed to form the current integer `k`.
            int remainder_needed = k % value;
            
            // If the count for this remainder is zero, we cannot form `k`.
            if (counts[remainder_needed] == 0) {
                // We've found the smallest missing integer.
                return k;
            }
            
            // Otherwise, we can form `k`. We "use" one number with this
            // remainder, so we decrement its count and check the next integer.
            counts[remainder_needed]--;
        }
        
        return -1; // Should be unreachable.
    }
};