/*
 * =====================================================================================
 *
 *       Filename:  assign_cookies.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/24 20时25分53秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

// 这里把正好能满足小孩胃口的饼干给到对应的小孩，即可尽可能的满足更多的小孩
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int g_index = 0;
        for (int cookie : s) {
            if (cookie >= g[g_index]) {
                res++;
                if (g_index < g.size() - 1) g_index++;
                else break;
            } else {
                continue;
            }
        }
        return res;
    }
};

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (g.size() == 0 || s.size() == 0) return 0;
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int g_i = 0, s_i = 0;
        while (g_i < g.size() && s_i < s.size()) {
            if (g[g_i] <= s[s_i]) {
                g_i++;
                s_i++;
            } else {
                s_i++;
            }
        }
        return g_i;
    }
};
