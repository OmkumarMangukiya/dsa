// https://leetcode.com/problems/vowels-game-in-a-string/?envType=daily-question&envId=2025-09-12
class Solution {
private:
    bool isVowel(char c){
        return c=='a' || c=='e' ||c=='i'||c=='o'||c=='u';
    }
public:
    bool doesAliceWin(string s) {
        //alice win ->true , bob win -> false
        bool ans=false;
        int i=0;
        int vowelCount=0;
        for(i=0;i<s.length();i++){
            if(isVowel(s[i])){
                vowelCount++;
            }
        }
        return (vowelCount>0)?true:false;
    }
};