class Solution {
public:
    int mod = 1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n+1,0); // track new peoples that get to know about the secret  
        dp[1]=1; // on day 1 : one person knows the secret
        long long newPeople=0;
        for(int i=2;i<=n;i++){ // start from day 2
            /**
            In the following loop we count how many new people will know the secret on the ith day. For that we can say that the number of people who has not forgotten the secret and the delay has passed will share the secret and that number of new people will know it. That's why I run loop from currentDay - forget + 1 to currentDay - delay 
            
            for(int j=i+1-forget;j<=i-delay;j++){ 
                if(j>0)
                dp[i]+=dp[j];
                dp[i] = dp[i]%mod;            
            }
            **/
            /**
            Now this question runs in O(N^2), so we can optimse it to O(N) using sliding window for the sum part.
            Everytime I need the sum of the currentDaya-forget+1 to currentDay - delay
            **/
            long long peoplecanShare = (i - delay >0)?dp[i-delay]:0;
            long long peopleForgot = (i-forget>0)?dp[i-forget]:0;
            newPeople =  (newPeople + peoplecanShare + mod-peopleForgot)%mod ;
            dp[i] = newPeople;

        }
        // Now we will sum up all the new people that got to know about the secret on ith day but we will only count those who haven't forgotten
        long long ret=0;
        for(int i =n-forget+1 ;i<=n;i++){
            ret+=dp[i];
            ret = ret%mod;
        }   
        return static_cast<int>(ret);
    }
};