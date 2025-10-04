// https://leetcode.com/problems/water-bottles-ii/description/
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalDrank = 0;
        int emptyBottles = 0;
        while (true) {
            if (numBottles > 0) {
                totalDrank += numBottles;
                emptyBottles += numBottles;
                numBottles = 0;
            }

            while (emptyBottles >= numExchange) {
                numBottles += 1;
                emptyBottles -= numExchange;
                numExchange += 1;
            }
            if (numBottles == 0) {
                return totalDrank;
            }
        }
    }
};