class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int,int>> q;
        int freshCount = 0;

        // Step 1: Add all rotten oranges to queue, count fresh ones
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        if (freshCount == 0) return 0;

        int minutes = 0;
        int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        // Step 2: BFS level by level (minute by minute)
        while (!q.empty() && freshCount > 0) {
            int size = q.size();
            minutes++;

            for (int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();

                for (auto& dir : directions) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];

                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols 
                        && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        freshCount--;
                        q.push({newRow, newCol});
                    }
                }
            }
        }

        return freshCount == 0 ? minutes : -1;
    }
};