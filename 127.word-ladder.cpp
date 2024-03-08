/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> leftOverWords;
        for (int i = 0; i < wordList.size(); i++) {
            leftOverWords.insert(wordList[i]);
        }
        queue<string> q;
        int level = 0;
        q.push(beginWord);
        while(!q.empty()) {
            queue<string> q2;
            while(!q.empty()) {
                string s = q.front();
                q.pop();
                if (s == endWord) {
                    return level;
                }
                vector<string> v;
                for (auto word: leftOverWords) {
                    if (isNeighbor(s, word)) {
                        q2.push(word);
                        v.push_back(word);
                    }
                }
                for (int i = 0; i < v.size(); i++) {
                    leftOverWords.erase(v[i]);
                }
            }
            level++;
            q.swap(q2);
        }
        return 0;
    }

    bool isNeighbor(string first, string second) {
        int count = 0;
        for (int i = 0; i < first.size(); i++) {
            if (first[i] != second[i]) {
                count++;
            }
        }
        if (count == 1) {
            return true;
        }
        return false;
    }

};
// @lc code=end