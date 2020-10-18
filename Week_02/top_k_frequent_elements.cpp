/*
 * =====================================================================================
 *
 *       Filename:  top_k_frequent_elements.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/18 19时31分26秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

// https://leetcode-cn.com/problems/top-k-frequent-elements/

// 1. Max heap: create max heap -> getMax() -> return vector<int> result
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> cnt;

        // 先用hashtable统计每个元素出现的次数，以元素本身作为key去做hashing，value为该元素出现的次数
        // 此处因为不能确定需要散列的key的数量，所以用STL的map去做hashtable，如果知道key的数量，则可以选择更简单的数组去做hashtable
        for (auto num : nums) cnt[num]++;

        // 直接把所有元素放到大顶堆，c++的STL的优先队列默认实现为大顶堆，此处频次作为key，元素本身作为value
        for (auto kv : cnt) {
            pq.push(pair{kv.second, kv.first});
        }

        // 直接取出前k个元素
        while(result.size() < k) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};

/* 这个解法相当于用了heap sort
 * Time complexity: O(NlogN)
 * 
 * 可以用小顶堆优化为O(NlogK)，具体做法如下
 * 每次插入新元素的时候，if (heap.size() > k) heap.pop()
 * 这样所有元素遍历完之后，小顶堆里面即为最高频的k个元素
 */
