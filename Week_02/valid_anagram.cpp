/*
 * =====================================================================================
 *
 *       Filename:  valid_anagram.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/18 17时45分19秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

/*
 * https://leetcode-cn.com/problems/valid-anagram/description/
 * 利用hashtable统计每个string里面的字符出现的次数
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int table[26] = {0};    // 由于只有小写字母，所以用数组实现哈希表，如果不知道需要散列的数据量，则可以直接用哈希表，比如map等
        // ascii码值-65作为各个字母的key，s中出现的字符则计数+1，f中出现的则-1，如果为异位词，则每个字符的计数均为0
        for (int i = 0; i < s.size(); i++) {
            table[s[i] - 'a']++;
            table[t[i] - 'a']--;
        }
        // 如果有不为零的，则不是异位词
        for (int count : table) {
            if (count != 0)
                return false;
        }
        return true;
    }
};
