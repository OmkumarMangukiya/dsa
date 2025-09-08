// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/?envType=daily-question&envId=2025-09-08
class Solution {
public:
    bool checkNoZero(int x , int i){
        while(x){
            if(x%10==0) return false;
            x=x/10;
        }
        while(i){
            if(i%10==0) return false;
            i=i/10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<=n;i++){
            int x = n-i;
            if(checkNoZero(x,i)){
                return {x,i};
            }
        }
        return {-1,-1};
    }
};