/*
 * =====================================================================================
 *
 *       Filename:  word_ladder.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/24 20时31分40秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

// Recursive solution (DFS) 记录每一个结果，取最小的那个
class Solution {
private:
    int res;
    unordered_set<string> set;
    void recur(string beginWord, string endWord, vector<string>& wordList, int level) {
        if (beginWord == endWord) {
            res = min(res, level + 1);
            return;
        }

        for (auto word : wordList) {
            if (set.count(word)) continue;  // visited 跳过
            int n = word.size();
            int diff = 0;
            for (int i = 0; i < n; i++) {
                if (beginWord.at(i) != word.at(i)) if (++diff > 1) break;
            }
            if (diff == 1 && !set.count(word)) {
                set.insert(word);
                recur(word, endWord, wordList, level + 1);
                set.erase(word);
            }
        }
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        res = INT_MAX;
        recur(beginWord, endWord, wordList, 0);
        return res == INT_MAX ? 0 : res;
    }
};

// BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dic(wordList.begin(), wordList.end());
        queue<string> queue;
        queue.push(beginWord);
        int ladder = 0;
        while (!queue.empty()) {
            int n = queue.size();
            for (int i = 0; i < n; i++) {
                string word = queue.front();
                queue.pop();
                if (word == endWord) {
                    return ++ladder;
                }
                // 找到下一层所有的合法的单词，也就是与当前层中所有节点只相差一个字符的单词，彼此相差一个字符的两个单词间建立通路
                dic.erase(word);
                int str_len = word.size();
                for (int j = 0; j < str_len; j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (dic.find(word) != dic.end()) queue.push(word);
                    }
                    word[j] = c;
                }
            }
            // 至此所有下一层的节点都已经入队，所以level + 1
            ladder++;
        }
        return 0;
    }
};

// BFS with optimized visited data using vector of bool
/*
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // TODO
    }
};
*/

// Two-ended BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dic(wordList.begin(), wordList.end()), head, tail, *phead, *ptail;
        if (dic.find(endWord) == dic.end()) return 0;

        head.insert(beginWord);
        tail.insert(endWord);
        int ladder = 2; // already 2
        while (!head.empty() && !tail.empty()) {
            if (head.size() < tail.size()) {
                phead = &head;
                ptail = &tail;
            } else {
                phead = &tail;
                ptail = &head;
            }
            unordered_set<string> temp;
            for (auto it = phead->begin(); it != phead->end(); it++) {
                string word = *it;
                int n = word.size();
                for (int i = 0; i < n; i++) {
                    char c = word[i];
                    for (int j = 0; j < 26; j++) {
                        word[i] = 'a' + j;
                        if (ptail->find(word) != ptail->end()) return ladder;
                        if (dic.find(word) != dic.end()) {
                            temp.insert(word);
                            dic.erase(word);
                        }
                    }
                    word[i] = c;
                }
            }
            ladder++;
            phead->swap(temp);
        }
        return 0;
    }
};


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ladder = 0;
        unordered_set<string> dic(wordList.begin(), wordList.end()), head, tail;
        if (dic.find(endWord) == dic.end()) return ladder;

        unordered_set<string> visited;
        head.insert(beginWord);
        tail.insert(endWord);
        ladder = 2;	// already inserted two nodes
        while (!head.empty()) {
            if (head.size() > tail.size()) {	// always start BFS from the end with less nodes
                head.swap(tail);
            }
            // find the next layer of node, word that only one character different from the previous word
            unordered_set<string> temp;
            for (auto word : head) {
                for (int i = 0; i < word.size(); i++) {
                    for (char j = 'a'; j <= 'z'; j++) {
                        char c = word[i];
                        word[i] = j;
                        if (tail.find(word) != tail.end()) return ladder;
                        if (visited.find(word) == visited.end() && dic.find(word) != dic.end()) {	// visited 和 dic 均为哈希表，所以find操作时间复杂度为O(1)
                            visited.insert(word);
                            temp.insert(word);
                        }
                        word[i] = c;
                    }
                }
            }
            ladder++;
            head.swap(temp);	// start BFS from the new layer
        }
        return 0;
    }
};
