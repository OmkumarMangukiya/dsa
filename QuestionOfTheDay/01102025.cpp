//https://leetcode.com/problems/water-bottles/description/
class Solution {
public:
    int numWaterBottles(int b, int n) {
        return b + (b - 1) / (n - 1);
    }
};
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrankBottles = numBottles; 
        int emptyBottles = numBottles;       

        while (emptyBottles >= numExchange) {
            int newFullBottles = emptyBottles / numExchange;

            totalDrankBottles += newFullBottles;

            emptyBottles = (emptyBottles % numExchange) + newFullBottles;
        }

        return totalDrankBottles;
    }
};