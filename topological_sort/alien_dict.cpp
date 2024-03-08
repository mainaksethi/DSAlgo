/**
 * A popular problem asked in interview using topological sort.
 * Little cumbersome solution.
*/

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
    string findOrder(string dict[], int N, int K) {
        unordered_map<char, int> indegree;
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, unordered_set<char>> reverseMap;
        unordered_set<char> charWithIndegree0;
        unordered_map<char, int> visited;
        
        
        for (int i= 0; i < sizeof(dict)/sizeof(dict[0]); i++) {
            for (int l = 0; l < dict[i].size(); l++) {
                charWithIndegree0.insert(dict[i][l]);
            }
            for (int j = i+1; j < sizeof(dict)/sizeof(dict[0]); j++) {
                for (int k = 0; k < dict[i].size() ; k++) {
                    if (dict[i][k] != dict[j][k]) {
                        adj[dict[j][k]].insert(dict[i][k]);
                        reverseMap[dict[i][k]].insert(dict[j][k]);
                        break;
                    }
                }
            }
        }
        for (auto it = adj.begin(); it != adj.end(); it++) {
            indegree[it->first] = (it->second).size();
            if (charWithIndegree0.find(it->first) != charWithIndegree0.end()) {
                charWithIndegree0.erase(it->first);
            }
        }
        queue<char> q;
        for (auto c: charWithIndegree0) {
            q.push(c);
            visited[c] = true;
        }
        string s;
        while(!q.empty()) {
            char c = q.front();
            q.pop();
            s = s + c;
            for (auto it = reverseMap[c].begin(); it != reverseMap[c].end(); it++) {
                indegree[*it]--;
                if (indegree[*it] == 0 && !visited[*it]) {
                    visited[*it] = true;
                    q.push(*it);
                }
            }
        }
        return s;
    }
};

int main() {
    string dict[] = {"a", "b"};
    Solution s;
    s.findOrder(dict, 2, 2);
    return 0;
}