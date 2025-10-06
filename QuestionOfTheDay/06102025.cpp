class Solution {
private:
    bool solve(vector<vector<int>>& grid, int level){
        // Now let's do BFS and see if the level is good enough to reach to n-1,n-1
        
        queue<pair<int,int>> q; // to maintain possible paths
        vector<vector<bool>> visited(grid.size(),vector<bool> (grid.size(),false)); // to mark visited cells
        q.push({0,0});
        visited[0][0]=true;
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop(); // pop front from the queue and append the possible neighbours 
            if(i==grid.size()-1 && j==grid.size()-1){
                return true;
            }
            // now explore all direction
            //left
            if(j-1>=0 && !(visited[i][j-1]) && grid[i][j-1] <=level){
                q.push({i,j-1});
                visited[i][j-1]=true;
            }
            //right
            if(j+1<grid.size() && !(visited[i][j+1]) && grid[i][j+1] <=level){
                q.push({i,j+1});
                visited[i][j+1] = true;
            }
            //up
            if(i-1>=0 && !(visited[i-1][j]) && grid[i-1][j] <= level){
                q.push({i-1,j});
                visited[i-1][j]= true;
            }
            //down
            if(i+1<grid.size() && !(visited[i+1][j]) && grid[i+1][j]<=level){
                q.push({i+1,j});
                visited[i+1][j] = true;
            }
        }
        return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        // I think this can be solved using binary search , I know the maximum and minimum of the answer so I can apply binary search on answer
        int n = grid.size();
        if(n==1) return grid[0][0];
        int low = grid[0][0];
        int high = n*n - 1;
        int ret=-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(solve(grid,mid)){
                ret = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ret;
    }
};