/*
 * =====================================================================================
 *
 *       Filename:  best_time_to_buy_and_sell_stock_ii.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/24 20时20分08秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

// greedy
// 只要第i + 1天的价格高于第i天的价格，就可以记录为利润，所以这里适用贪心法，把每一天的最大相加即可得到最终的最大利润
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            if (prices[i] < prices[i + 1]) profit += prices[i + 1] - prices[i];
        }
        return profit;
    }
};
