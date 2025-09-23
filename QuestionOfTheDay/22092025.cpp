//https://leetcode.com/problems/count-elements-with-maximum-frequency/?envType=daily-question&envId=2025-09-22
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ret=0;

        unordered_map<int,int>mp;
        for(auto num : nums){
            mp[num]++;
        }

        vector<pair<int,int>> v;
        for(auto m : mp){
            v.push_back({m.second , m.first});
        }
        sort(v.begin() ,v.end(),[](const auto &a , const auto &b){
            return a.first > b.first;
        });
        int num = 0;
        for(auto n : v){
            num = n.first;
            break;
        }
        for(auto n : v){
            if(num!=n.first) break;
            ret+=n.first;
        }
        return ret;
    }
};