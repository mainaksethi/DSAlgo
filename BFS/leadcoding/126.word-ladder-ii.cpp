/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 * 
 * A non-trivial implementation of B.F.S
 * with tracking all the previous nodes.
 */

// @lc code=start
class Solution {
public:
    struct Node {
        vector<string> trail;
        string s;
        Node(string s, vector<string> trail): s(s), trail(trail) {};
        Node(): s(""), trail(vector<string>()) {};
    };

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> visited;
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> adj;
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i+1; j < wordList.size(); j++) {
                if (calculateDiff(wordList[i], wordList[j]) == 1) {
                    if (adj.find(wordList[i]) == adj.end()) {
                        vector<string> v;
                        adj[wordList[i]] = v;
                    }
                    if (adj.find(wordList[j]) == adj.end()) {
                        vector<string> v;
                        adj[wordList[j]] = v;
                    }
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        vector<string> trail;
        bfs(beginWord, endWord, wordList, visited, ans, trail, adj);
        return ans;
    }

    void bfs(string beginWord, string endWord, vector<string>& wordList, 
        unordered_map<string, bool> &visited, vector<vector<string>> &ans,
        vector<string> trail, unordered_map<string, vector<string>> &adj) {
            queue<Node> q;
            vector<string> v;
            v.push_back(beginWord);
            Node n = Node(beginWord, v);
            q.push(n);
            bool found = false;
            visited[beginWord] = true;
            int level = 0;
            while(!q.empty()) {
                queue<Node> q2;
                unordered_set<string> toBeMarkedVisited;
                while(!q.empty()) {
                    Node n = q.front();
                    q.pop();
                    string s = n.s;
                    vector<string> trail = n.trail;
                    vector<string> neighbors;
                    if (adj.find(s) != adj.end()) {
                        neighbors = adj[s];
                    }
                    for (int i = 0; i < neighbors.size(); i++) {
                        if (visited[neighbors[i]]) {
                            continue;
                        } else {
                            vector<string> v1 = trail;
                            v1.push_back(neighbors[i]);
                            if (neighbors[i] == endWord) {
                                found = true;
                                ans.push_back(v1);
                            }
                            Node n = Node(neighbors[i], v1);
                            q2.push(n);
                            toBeMarkedVisited.insert(neighbors[i]);
                        }
                    }
                }
                for (string s: toBeMarkedVisited) {
                    visited[s] = true;
                }
                level++;
                q.swap(q2);
                if (found) {
                    break;
                }
            }
            return;
        }

    int calculateDiff(string s1, string s2) {
        int charsdiff = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                charsdiff++;
            }
        }
        return charsdiff;
    }
};// @lc code=end

