// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/?envType=daily-question&envId=2025-10-08
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin() , potions.end());
        int n = spells.size();
        vector<int> ret(n);
        for(int i =0 ; i<n ; i++){
            auto it = lower_bound(potions.begin(), potions.end(),(success + (long long)spells[i]-1)/ (long long)spells[i]);
            int dist = distance(it,potions.end());
            ret[i] = dist;
        }
        return ret;
    }
};