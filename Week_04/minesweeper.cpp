/*
 * =====================================================================================
 *
 *       Filename:  minesweeper.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/24 20时38分37秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

// BFS
class Solution {
private:
    int d_x[8] = {0, 1, 0, -1, 1, 1, -1, -1};
    int d_y[8] = {1, 0, -1, 0, 1, -1, 1, -1};
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board.size() == 0) return board;

        int nr = board.size();
        int nc = board[0].size();
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
        queue<pair<int, int>> queue;
        queue.push({click[0], click[1]});
        visited[click[0]][click[1]] = 1;
        while (!queue.empty()) {
            auto node = queue.front();
            queue.pop();
            int row = node.first, col = node.second;
            if (board[row][col] == 'M') {
                board[row][col] = 'X';
                break;
            }
            int bombs = 0;
            for (int i = 0; i < 8; i++) {
                int x = row + d_x[i];
                int y = col + d_y[i];
                if (x < 0 || x >= nr || y < 0 || y >= nc) continue;
                if (board[x][y] == 'M') bombs++;
            }
            if (bombs == 0) {
                board[row][col] = 'B';
                for (int i = 0; i < 8; i++) {
                    int x = row + d_x[i];
                    int y = col + d_y[i];
                    if (x < 0 || x >= nr || y < 0 || y >= nc || board[x][y] != 'E' || visited[x][y]) continue;
                    queue.push({x, y});
                    visited[x][y] = 1;
                }
            } else board[row][col] = '0' + bombs;
        }
        return board;
    }
};
