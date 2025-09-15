https://leetcode.com/problems/maximum-number-of-words-you-can-type/?envType=daily-question&envId=2025-09-15
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken;
        for(char c : brokenLetters){
            broken.insert(c);
        }
        istringstream iss(text);
        string word;
        int res=0;
        while (iss >> word) {
            int pos=1;
            for(char c : word){
                if(broken.count(c)){
                    pos=0;
                    break;
                }
            }
            if(pos) res++;
        }
        return res;
    }
};