// https://leetcode.com/problems/pacific-atlantic-water-flow/?envType=daily-question&envId=2025-10-05
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // find a flow for pacific and atlantic and then do their intersection
        // I will do it reverse first see from border : e.g. : for pacific
        // insert all top and left cell into queue pop them one by one and see
        // if we can create a flow and also keep a visited set for both to
        // ensure we are not revisted the cell again
        vector<vector<int>> ret;

         int row = heights.size();
         int col = heights[0].size();

        // visited matrix , queue for both
        vector<vector<bool>> pacific(row, vector<bool>(col, false));
        vector<vector<bool>> atlantic(row, vector<bool>(col, false));

        queue<pair<int,int>> pacific_q;
        queue<pair<int,int>> atlantic_q;
        // for pacific first insert all nodes which fall in pacific
        for (int i = 0; i < row; i++) {
            pacific_q.push({i,0});
            pacific[i][0] = true;
        }
        for (int i = 0; i < col; i++) {
            pacific_q.push({0,i});
            pacific[0][i] = true;
        }
        while (!pacific_q.empty()) {
            auto [r, c] = pacific_q.front();
            pacific_q.pop();
            // now we get their neighbour for each check 3 things
            // 1. not out of bound index
            // 2. not visited
            // 3. height should be greater than current
            // left
            if ((c - 1 >= 0) && !(pacific[r][c - 1]) &&
                heights[r][c - 1] >= heights[r][c]) {
                pacific[r][c - 1] = true;
                pacific_q.push({r , c - 1});
            }
            // right
            if ((c + 1 < col) && !(pacific[r][c + 1]) &&
                heights[r][c + 1] >= heights[r][c]) {
                pacific[r][c + 1] = true;
                pacific_q.push({r , c + 1});
            }
            // up
            if ((r - 1 >= 0) && !(pacific[r - 1][c]) &&
                heights[r - 1][c] >= heights[r][c]) {
                pacific[r - 1][c] = true;
                pacific_q.push({r - 1, c});
            }
            // down
            if ((r + 1 < row) && !(pacific[r + 1][c]) &&
                heights[r + 1][c] >= heights[r][c]) {
                pacific[r + 1][c] = true;
                pacific_q.push({r +1, c });
            }
        }
        // same for atlantic
        for (int i = 0; i < row; i++) {
            atlantic_q.push({i,col-1});
            atlantic[i][col-1] = true;
        }
        for (int i = 0; i < col; i++) {
            atlantic_q.push({row-1,i});
            atlantic[row-1][i] = true;
        }
        while (!atlantic_q.empty()) {
            auto [r, c] = atlantic_q.front();
            atlantic_q.pop();
            //left
            if ((c - 1 >= 0) && !(atlantic[r][c - 1]) &&
                heights[r][c - 1] >= heights[r][c]) {
                atlantic[r][c - 1] = true;
                atlantic_q.push({r , c - 1});
            }
            // right
            if ((c + 1 < col) && !(atlantic[r][c + 1]) &&
                heights[r][c + 1] >= heights[r][c]) {
                atlantic[r][c + 1] = true;
                atlantic_q.push({r , c + 1});
            }
            // up
            if ((r - 1 >= 0) && !(atlantic[r - 1][c]) &&
                heights[r - 1][c] >= heights[r][c]) {
                atlantic[r - 1][c] = true;
                atlantic_q.push({r - 1 , c });
            }
            // down
            if ((r + 1 < row) && !(atlantic[r + 1][c]) &&
                heights[r + 1][c] >= heights[r][c]) {
                atlantic[r + 1][c] = true;
                atlantic_q.push({r +1 , c });
            }
        }
        // now do intersection
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ret.push_back({i,j});
                }
            }
        }

        return ret;
    }
};