There are `n` children standing in a line. Each child is assigned a rating value given in the integer array `ratings`.

You are giving candies to these children subjected to the following requirements:

- Each child must have at least one candy.
- Children with a higher rating get more candies than their neighbors.

Return _the minimum number of candies you need to have to distribute the candies to the children_.

```
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
```

Constrain :  `1 <= n <= 2 * 10^4`

First Thought: Traverse from left to right and add to counter as per neighbor but this greedy approach fails when there is something like this 2 , 10 ,2,1

Approach 1: - We have to do two traverse ()
1. left to right and see if a person needs more candy by seeing the person before it.
2. right to left and see if the person needs more candy by seeing the person after it. Now take the maximum for each person and sum it and that would be the answer.
TC : `O(N)`     SC : `O(N)`

```cpp
int candy(vector<int>& ratings) {
        int n =ratings.size();
        if(n==1) return 1;
        vector<int> L2R(n,1);
        for(int i =1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                L2R[i]=max(L2R[i-1]+1,L2R[i]);
            }
        }
        for(int i =n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                L2R[i]=max(L2R[i+1]+1,L2R[i]);
            }
        }
        return accumulate(L2R.begin(),L2R.end(),0);
    }
```

Approach 2:- Think the array as the mountains when there is increasing order there is a up steep and when its decreasing there is a downward steep.
TC : `O(N)`     SC : `O(1)`

```cpp
int candy(vector<int>& ratings) {
        int n =ratings.size();
        int candy=n;
        int i=1;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                i++;
                continue;
            }
            int peak=0;
            while(ratings[i] >ratings[i-1]){
                peak++;
                candy+=peak;
                i++;
                if(i==n){
                    return candy;
                }
            }
            int dip=0;
            while(i<n && ratings[i]<ratings[i-1]){
                dip++;
                candy+=dip;
                i++;
            }
            candy-=min(peak,dip);
        }
        return candy;
    }
```