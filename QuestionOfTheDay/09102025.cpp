// https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/submissions/1796353413/?envType=daily-question&envId=2025-10-09
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> finishTime(n,0);
        for(int i =0 ;i<m ; i++){
            finishTime[0] += skill[0]*mana[i];
            for(int j=1;j<n;j++){
                finishTime[j] = max(finishTime[j] , finishTime[j-1])  + 1LL*skill[j]*mana[i];
            }
            for(int j = n-1 ; j>0 ; j--){
                finishTime[j-1] = finishTime[j
                ]- mana[i]*skill[j];
            }
        }
        return finishTime[n-1];
    }
};