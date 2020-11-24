/*
 * =====================================================================================
 *
 *       Filename:  word_ladder_ii.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/24 20时41分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

// 以下代码未通过测试，在本题block住了5天，思路很简单，写了无数遍，总是写不对。。。死磕耗费太多时间和精力，最终放弃
// 思路 : 双向BFS -> 记录所有的successor -> dfs结果图，找到所有的path，注意方向
class Solution {
private:
    vector<vector<string>> res;
    vector<string> cur;
    unordered_map<string, unordered_set<string>> tree;
    unordered_set<string> dfs_visited;
    // DFS the nodes to generate the final result
    void generate_result(string beginWord, string endWord) {
        if (beginWord == endWord) {
            cur.push_back(beginWord);
            res.push_back(cur);
            return;
        }
        
        if (dfs_visited.count(beginWord)) return;

        cur.push_back(beginWord);
        dfs_visited.insert(beginWord);
        for (auto word : tree[beginWord]) {
            generate_result(word, endWord);
            cur.pop_back();
        }
    }

    void add_to_tree(string start, string end, bool reversed) {
        if (!reversed) tree[start].insert(end);
        else tree[end].insert(start);
    }

    void print_tree(unordered_map<string, unordered_set<string>>& tree) {
        for (auto it = tree.begin(); it != tree.end(); it++) {
            cout << it->first << endl;
            for (auto word: it->second) {
                cout << "   " << word << endl;
            }
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dic(wordList.begin(), wordList.end()), begin_set, end_set;
        if (dic.find(endWord) == dic.end()) return res;

        unordered_set<string> visited;
        // visited.insert(beginWord);
        // visited.insert(endWord);
        begin_set.insert(beginWord);
        end_set.insert(endWord);
        bool reversed = false, found = false;
        while (!begin_set.empty()) {
            if (begin_set.size() > end_set.size()) {
                begin_set.swap(end_set);
                reversed = !reversed;
            }
            unordered_set<string> temp;
            for (auto word : begin_set) {
                for (int i = 0; i < word.size(); i++) {
                    for (char j = 'a'; j <= 'z'; j++) {
                        string t_word = word;
                        char c = word[i];
                        word[i] = j;
                        if (end_set.find(word) != end_set.end()) {
                            add_to_tree(t_word, word, reversed);
                            found = true;
                        }
                        if (visited.find(word) == visited.end() && dic.find(word) != dic.end()) {
                            temp.insert(word);
                            visited.insert(word);
                            add_to_tree(t_word, word, reversed);
                        }
                        word[i] = c;
                    }
                }
            }
            if (found) {
                print_tree(tree);
                generate_result(beginWord, endWord);
                return res;
            } else begin_set.swap(temp);
        }
        return res;
    }
};
