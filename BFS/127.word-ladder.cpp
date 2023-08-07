
// Problem: https://leetcode.com/problems/word-ladder/
// Type: 
// 1. Make graph with bfs.
// DebugNotes: 
// 1. c++ if character present in string => str.find(c) != std::string::npos
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> graph;
        wordList.push_back(beginWord);
        make_graph(graph, wordList);
        return bfs(graph, beginWord, endWord);
    }

    int bfs(unordered_map<string, vector<string>> &graph,
        string beginWord,
        string endWord) {
            if (beginWord == endWord) {
                return 0;
            }
            unordered_map<string, bool> visited;
            queue<string> q;
            q.push(beginWord);
            visited[beginWord] = true;
            int level = 1;
            while(!q.empty()) {
                queue<string> q2;
                while(!q.empty()) {
                    string val = q.front();
                    q.pop();
                    if (val == endWord) {
                        return level;
                    }
                    for (auto adj: graph[val]) {
                        if (!visited[adj]) {
                            // Always note to mark visited true before pushing.
                            visited[adj] = true;
                            q2.push(adj);
                        }
                    }
                }
                q.swap(q2);
                level++;
            }
            return 0;
        }

        // Standard way to make graph using unordered_map<type, vector<type>>
        void make_graph(unordered_map<string, 
                        vector<string>> &graph, 
                        vector<string>& wordList) {
            for (int i = 0; i < wordList.size(); i++) {
                for (int j = i+1; j < wordList.size(); j++) {
                    if (isAdjacent(wordList[i], wordList[j])) {
                        push(graph, wordList[i], wordList[j]);
                        push(graph, wordList[j], wordList[i]);
                    }
                }
            }
            return;
        }

        bool isAdjacent(string s1, string s2) {
            int count = 0;
            if (s1.size() < s2.size()) {
                string temp = s2;
                s2 = s1;
                s1 = temp;
            }
            for (int i = 0; i < s2.size(); i++) {
                if (s1[i] != s2[i]) {
                    count++;
                }
            }
            count += (s1.size() - s2.size());
            return count == 1 ? true : false;
        }

        void push(unordered_map<string, vector<string>> &graph, string parent, string child) {
            graph[parent].push_back(child);
        }
};

// int main() {
//     Solution s;
//     vector<string> v{"lest","leet","lose","code","lode","robe","lost"};
//     s.ladderLength("leet", "code", v);
// }

// @lc code=end

