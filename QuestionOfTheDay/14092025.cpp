//https://leetcode.com/problems/vowel-spellchecker/description/?envType=daily-question&envId=2025-09-14
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactSet(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseMap;
        unordered_map<string, string> vowelMap;

        auto toLower = [](const string& s) {
            string t = s;
            for (char& c : t) c = tolower(c);
            return t;
        };

        auto devowel = [&](const string& s) {
            string t = toLower(s);
            for (char& c : t) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                    c = '*';
            }
            return t;
        };

        // Build caseMap and vowelMap
        for (const string& word : wordlist) {
            string lower = toLower(word);
            if (!caseMap.count(lower)) {
                caseMap[lower] = word;
            }
            string key = devowel(lower);
            if (!vowelMap.count(key)) {
                vowelMap[key] = word;
            }
        }

        vector<string> result;
        result.reserve(queries.size());

        // Process queries
        for (const string& q : queries) {
            if (exactSet.count(q)) {
                result.push_back(q);
            } else {
                string lower = toLower(q);
                if (caseMap.count(lower)) {
                    result.push_back(caseMap[lower]);
                } else {
                    string key = devowel(lower);
                    if (vowelMap.count(key)) {
                        result.push_back(vowelMap[key]);
                    } else {
                        result.push_back("");
                    }
                }
            }
        }
        return result;
    }
};
