class Solution {
private:
    //https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/description/?envType=daily-question&envId=2025-09-02
    bool checkUpperLeft(vector<int> a , vector<int> b){
        return ((a[0]<=b[0] && a[1]>=b[1]) );
    }
    bool checkPointInPath(vector<int> a , vector<int> b , vector<vector<int>>& points){
        int n = points.size();
        for(int i =0;i<n;i++){
            if(a==points[i] || b==points[i]) continue;
            if((a[0]<=points[i][0] && points[i][0]<=b[0] && a[1]>=points[i][1] && points[i][1]>=b[1])){
                return false;
            }
        }
        return true;
    }
public:
    
    int numberOfPairs(vector<vector<int>>& points) {
        // have to see two things for each pair of points
        // one point in the pair has to be upper left of another
        // if two points are in the same line vertically or horizontally then I need to check for line and if they form a rectangle then I need to check the border and inside of rectangle
        
        // Approach 
        // first i will take two pairs and then check if first is upper left of second if yes then proceed otherwise skip that pair
        // then i would check if there is a point between them if yes then false otherwise count++
        int n = points.size();
        int count=0;
        for(int a =0 ;a<n;a++){
            for(int b = 0 ; b<n;b++ ){
                //skip if same
                if(a==b) continue;
                //skip because a is not upper left of b
                if(!checkUpperLeft(points[a],points[b])) continue;
                //skip if there is a point which is inside or on this line or rectangle
                if(!checkPointInPath(points[a],points[b],points)) continue;
                // we got a valid pair so do count++
                count++;

            }
        }
        return count;
    }
};