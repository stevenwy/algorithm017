/*
 * =====================================================================================
 *
 *       Filename:  walking_robot_simulation.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/24 20时44分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // 默认朝北，即y轴为+1
        int d_x[4] = {0, 1, 0, -1};
        int d_y[4] = {1, 0, -1, 0};
        int x = 0, y = 0, di = 0;
        unordered_set<pair<int, int>, pair_hash> obstacles_set;    // speed up the process of obstacle identification
        for (auto obstacle : obstacles)
            obstacles_set.insert(make_pair(obstacle[0], obstacle[1]));
        int res = 0;
        for (int cmd : commands) {
            if (cmd == -1) di = (di + 1) % 4;
            else if (cmd == -2) di = (di + 3) % 4;
            else {
                for (int i = 0; i < cmd; i++) {
                    int nx = x + d_x[di];
                    int ny = y + d_y[di];
                    if (obstacles_set.find(make_pair(nx, ny)) == obstacles_set.end()) {
                        x = nx;
                        y = ny;
                        res = max(res, x * x + y * y);
                    }
                }
            }
        }
        return res;
    }
};
