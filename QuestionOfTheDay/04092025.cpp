// https://leetcode.com/problems/find-closest-person/?envType=daily-question&envId=2025-09-04
class Solution {
public:
    int findClosest(int x, int y, int z) {
        return (abs(x-z)==abs(y-z))?0:(abs(x-z)<abs(y-z))?1:2;
    }
};