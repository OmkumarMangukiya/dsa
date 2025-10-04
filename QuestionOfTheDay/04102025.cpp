// https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int l=0, r= n-1;
        int maxArea= 0;
        while(l<r){
            int area= (r-l)*min(height[l], height[r]);
            maxArea= max(maxArea, area);
            if(height[l]<height[r]) l+=1;
            else r-=1;
        }
        return maxArea;
    }
};