/*
 * =====================================================================================
 *
 *       Filename:  number_of_islands.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/24 20时38分06秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

// DFS
class Solution {
private:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        int r = grid.size();
        int c = grid[0].size();

        grid[row][col] = '0';

        if (row - 1 >= 0 && grid[row - 1][col] == '1') dfs(grid, row - 1, col);
        if (row + 1 < r && grid[row + 1][col] == '1') dfs(grid, row + 1, col);
        if (col - 1 >= 0 && grid[row][col - 1] == '1') dfs(grid, row, col - 1);
        if (col + 1 < c && grid[row][col + 1] == '1') dfs(grid, row, col + 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (!row) return 0;
        int col = grid[0].size();

        int res = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    ++res;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};

// BFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (!row) return 0;
        int col = grid[0].size();

        int res = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    ++res;
                    grid[i][j] = '0';
                    queue<pair<int, int>> queue;
                    queue.push({i, j});
                    while (!queue.empty()) {
                        auto node = queue.front();
                        queue.pop();
                        int r = node.first, c = node.second;
                        if (r - 1 >= 0 && grid[r - 1][c] == '1') {
                            queue.push({r - 1, c});
                            grid[r - 1][c] = '0';
                        }
                        if (r + 1 < row && grid[r + 1][c] == '1') {
                            queue.push({r + 1, c});
                            grid[r + 1][c] = '0';
                        }
                        if (c - 1 >= 0 && grid[r][c - 1] == '1') {
                            queue.push({r, c - 1});
                            grid[r][c - 1] = '0';
                        }
                        if (c + 1 < col && grid[r][c + 1] == '1') {
                            queue.push({r, c + 1});
                            grid[r][c + 1] = '0';
                        }
                    }
                }
            }
        }
        return res;
    }
};
