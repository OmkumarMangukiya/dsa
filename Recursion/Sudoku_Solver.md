```cpp
class Solution {
public:
    // store data here; in rows we store the index and in columns we store the number (digits 1–9)
    int row[9][10] = {};
    int col[9][10] = {};
    int box[9][10] = {};

    // pointer to the board to update it directly
    vector<vector<char>>* board;

    void solveSudoku(vector<vector<char>>& board) {
        this->board = &board;

        // Initialize the tracking arrays
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int d = board[i][j] - '0';
                    row[i][d] = 1;
                    col[j][d] = 1;
                    int boxIndex = (i / 3) * 3 + j / 3;
                    box[boxIndex][d] = 1;
                }
            }
        }
        solve();
    }

    bool solve() {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if ((*board)[i][j] == '.') {
                    for (int k = 1; k <= 9; ++k) {
                        int boxIndex = (i / 3) * 3 + j / 3;

                        // Check if k can be placed ; we use constrain programming
                        if (!row[i][k] && !col[j][k] && !box[boxIndex][k]) {
                            // Place the number
                            (*board)[i][j] = k + '0';
                            row[i][k] = 1;
                            col[j][k] = 1;
                            box[boxIndex][k] = 1;

                            // Recur to solve rest
                            if (solve()) return true;

                            // Backtrack
                            (*board)[i][j] = '.';
                            row[i][k] = 0;
                            col[j][k] = 0;
                            box[boxIndex][k] = 0;
                        }
                    }
                    // If no number can be placed here, backtrack
                    return false;
                }
            }
        }
        // All cells are filled
        return true;
    }
};
```
