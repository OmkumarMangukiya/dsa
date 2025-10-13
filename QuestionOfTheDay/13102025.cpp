//https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/submissions/1799880700/?envType=daily-question&envId=2025-10-13
class Solution {
public:
    bool anagram(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
    
    vector<string> removeAnagrams(vector<string>& words) {
        if (words.empty()) {
            return {};
        }
        
        vector<string> result;
        result.push_back(words[0]);
        
        for (int i = 1; i < words.size(); ++i) {
            if (!anagram(result.back(), words[i])) {
                result.push_back(words[i]);
            }
        }
        
        return result;
    }
};