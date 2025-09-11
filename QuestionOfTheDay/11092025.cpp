//https://leetcode.com/problems/sort-vowels-in-a-string/?envType=daily-question&envId=2025-09-11
class Solution {
public:
    string sortVowels(string s) {
        string vowels = "AEIOUaeiou";
        vector<int> freq(128, 0); // ASCII frequency table

        // Count vowel frequencies
        for (char c : s) {
            if (isVowel(c)) {
                freq[c]++;
            }
        }

        // Pointer to smallest available vowel in ASCII order
        int ptr = 0;
        while (ptr < 128 && freq[ptr] == 0) ptr++;

        string ret = s;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                // Find next available vowel
                while (ptr < 128 && freq[ptr] == 0) ptr++;
                ret[i] = (char)ptr;
                freq[ptr]--;
            }
        }
        return ret;
    }

private:
    bool isVowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
               c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }
};
