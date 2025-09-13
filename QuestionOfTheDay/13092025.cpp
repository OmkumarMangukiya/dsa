//https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/
class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxFreqSum(string s) {
        vector<int> hash(125,0);
        int consMaxFreq=0;
        int vowMaxFreq=0;
        for(char c : s){
            hash[c-'a']++;
            if(!isVowel(c)){
                consMaxFreq = max(consMaxFreq,hash[c-'a']);
            }
            else{
                vowMaxFreq = max(vowMaxFreq,hash[c-'a']);
            }
        }
        return vowMaxFreq+consMaxFreq;
    }
};