class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        // iterate over all possible 3x3 subgrids
        for (int i = 0; i + 2 < n; i++) {
            for (int j = 0; j + 2 < m; j++) {

                vector<int> nums;
                bool valid = true;

                // collect all 9 numbers
                for (int r = i; r < i + 3; r++) {
                    for (int c = j; c < j + 3; c++) {
                        nums.push_back(grid[r][c]);
                    }
                }

                // check numbers are from 1 to 9 and distinct
                sort(nums.begin(), nums.end());
                for (int k = 0; k < 9; k++) {
                    if (nums[k] != k + 1) {
                        valid = false;
                        break;
                    }
                }

                if (!valid) continue;

                // calculate sums
                int row1 = grid[i][j] + grid[i][j+1] + grid[i][j+2];
                int row2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
                int row3 = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];

                int col1 = grid[i][j] + grid[i+1][j] + grid[i+2][j];
                int col2 = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
                int col3 = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];

                int diag1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
                int diag2 = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];

                // check all sums are equal
                if (row1 == row2 && row2 == row3 &&
                    row3 == col1 && col1 == col2 &&
                    col2 == col3 &&
                    col3 == diag1 && diag1 == diag2) {
                    count++;
                }
            }
        }

        return count;
    }
};
