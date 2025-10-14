// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/?envType=daily-question&envId=2025-10-14
class Solution {
public:
    bool check(int i , vector<int>& nums, int k){
        for(int j =i ;j < i+k-1 ; j++){
            if(nums[j] >= nums[j+1]){
                return false;
            }
        }
        for(int j =i+k ;j < i+2*k-1 ; j++){
            if(nums[j] >= nums[j+1]){
                return false;
            }
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if (nums.size() < 2 * k) {
            return false;
        }
        for(int i =0 ;i<=nums.size()-2*k ; i++){
            if(check(i,nums,k)){
                return true;
            }
        }
        return false;
    }
};