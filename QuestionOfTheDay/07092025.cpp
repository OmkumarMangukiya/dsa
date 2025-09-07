https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/?envType=daily-question&envId=2025-09-07
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ret;
        if(n&1){
            int cnt = -(n/2);
            for(int i =0;i<n;i++){
                ret.push_back(cnt);
                cnt++;
            }
        }
        else{
            int cnt = -(n/2);
            for(int i =0;i<n;i++){
                if(cnt!=0)
                ret.push_back(cnt);
                cnt++;
            }
        }
        return ret;
    }
};