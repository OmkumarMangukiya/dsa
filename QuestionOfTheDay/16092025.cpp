//https://leetcode.com/problems/replace-non-coprime-numbers-in-array/?envType=daily-question&envId=2025-09-16
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        // find adjacent non-coprime
        // replace them with their LCM
        // we will use vector as a stack (doing this so that we can save some time because if we use stack we need to reverse it at last)
        int n = nums.size();
        if(n==1){
            return nums;
        }
        vector<int> st;
        for(int num : nums){
            st.push_back(num);
            while(st.size()>=2){
                int num1 = st.back();
                st.pop_back();
                int num2 = st.back();
                st.pop_back();
                if(__gcd(num1,num2)>1){
                    st.push_back(lcm(num1,num2));
                }else{
                    st.push_back(num2);
                    st.push_back(num1);
                    break;
                }
            }
        }
        return st;
    }
};