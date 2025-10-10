//https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/description/?envType=daily-question&envId=2025-10-10
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> ret = energy;
        for(int i =n-k-1 ; i>=0 ;i--){
            ret[i] += ret[i+k];
        }
        return *max_element(ret.begin(), ret.end());
    }
};