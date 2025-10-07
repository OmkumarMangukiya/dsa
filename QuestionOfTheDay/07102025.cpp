//https://leetcode.com/problems/avoid-flood-in-the-city/?envType=daily-question&envId=2025-10-07
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ret(rains.size(), 1);
        unordered_map<int, int> rainy;
        set<int> st;
        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                st.insert(i);
            } else {
                ret[i] = -1;
                if (rainy.count(rains[i])) {
                    // rain is going to occur second time
                    // find the earlist dry day before the rain occur here
                    auto it = st.lower_bound(rainy[rains[i]]);
                    //flood occurs
                    if(it==st.end()){
                        return {};
                    }
                    // dried rains[i] lake at *it dry day
                    ret[*it] = rains[i];
                    // erase *it day cause we dried rains[i] lake
                    st.erase(*it);
                }
                rainy[rains[i]] = i;
            }
        }

        return ret;
    }
};