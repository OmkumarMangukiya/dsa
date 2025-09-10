//https://leetcode.com/problems/minimum-number-of-people-to-teach/?envType=daily-question&envId=2025-09-10
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        // users to whom we need to teach
        unordered_set<int> users;

        for(auto& frnd : friendships){
            int user1 = frnd[0] - 1;
            int user2 = frnd[1] - 1;
            bool canCommunicate = false;

            for(int language1 : languages[user1]){
                for(int language2 : languages[user2]){
                    if(language1 == language2){
                        canCommunicate = true;
                        break;
                    }
                }
                if(canCommunicate) break;
            }
            if(!canCommunicate){
                users.insert(user1);
                users.insert(user2);
            }
        }
        int minUsersToTeach = languages.size()+1;
        for (int language = 1; language <= n; language++) {
            int count = 0;

            for (int user : users) {
                bool knowsLanguage = false;
                for (int lang : languages[user]) {
                    if (lang == language) {
                        knowsLanguage = true;
                        break;
                    }
                }
                if (!knowsLanguage) count++;
            }

            minUsersToTeach = min(minUsersToTeach, count);
        }

        return minUsersToTeach;
    }
};